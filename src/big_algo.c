/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:54 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 03:29:29 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_place(t_list **stack_a, t_list **stack_b, t_list *last)
{
	if ((*stack_b)->content > last->content && (*stack_b)->content < (*stack_a)->content)
		return (1);
	return (0);
}

void	ft_init_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while ((*stack_a)->next->next->next)
	{
		if ((*stack_a)->content == data->min || (*stack_a)->content == data->max)
			ft_rotate(*stack_a, RA);
		else if ((*stack_a)->content < data->lowmedian && data->pos_low > 0)
		{
			ft_rotate(*stack_a, RA);	
			data->pos_low--;
		}
		else if ((*stack_a)->content < data->bigmedian)
			ft_push_stack(stack_b, stack_a, PB);
		else if ((*stack_a)->content > data->bigmedian)
		{
			ft_push_stack(stack_b, stack_a, PB);
			ft_rotate(*stack_b, RB);
		}
		else
			ft_push_stack(stack_b, stack_a, PB);
	}
	ft_algo_three(*stack_a);
}

void	ft_select_best_move(t_list **stack_a, t_list **stack_b)
{
	int best_a;
	int best_b;
	int best_move;
	t_list	*tmp_a;
	t_list	*tmp_b;
	
	best_move = 2147483647;
	tmp_b = *stack_b;
	(*stack_b)->pos = 0;
	while (tmp_b)
	{
		(*stack_a)->pos = 0;
		tmp_a = *stack_a;
		while (tmp_a->next && !(tmp_b->content > tmp_a->content && tmp_b->content < tmp_a->next->content))
		{
			if ((*stack_a)->pos == ft_lstsize(*stack_a) / 2)
				(*stack_a)->pos = (ft_lstsize(*stack_a) - (*stack_a)->pos) * - 1;
			(*stack_a)->pos++;
			tmp_a = tmp_a->next;
		}
		if (tmp_a->next && tmp_b->content > tmp_a->content && tmp_b->content < tmp_a->next->content)
			(*stack_a)->pos++;
		if (abs((*stack_a)->pos) + abs((*stack_b)->pos) < abs(best_move))
		{
			best_move = abs((*stack_a)->pos) + abs((*stack_b)->pos);
			best_b = (*stack_b)->pos;
			best_a = (*stack_a)->pos;
		}
		if ((*stack_b)->pos == ft_lstsize(*stack_b) / 2)
			(*stack_b)->pos = (ft_lstsize(*stack_b) - (*stack_b)->pos) * - 1;
		(*stack_b)->pos++;
		tmp_b = tmp_b->next;
	}
	ft_move(stack_a, stack_b, best_a, best_b);
}

void	ft_rollthatdude(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list *tmp;
	static int place_min = 0;
	static int place_median = 0;
	tmp = *stack_a;
	while (tmp->content != data->min)
	{
		place_min++;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp->content != data->median)
	{
		place_median++;
		tmp = tmp->next;
	}

	while (!ft_is_sort(*stack_a, *stack_b))
	{
		if (place_min < place_median)
			ft_rotate(*stack_a, RA);
		else
			ft_reverse_rotate(*stack_a, RRA);
	}
}

void	ft_big_algo(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	ft_init_sort(stack_a, stack_b, data);
	while (*stack_b && !ft_is_sort(*stack_a, *stack_b))
	{
		last = ft_lstlast(*stack_a);
		if (ft_place(stack_a, stack_b, last))
		{
			ft_push_stack(stack_a, stack_b, PA);
		}
		else
			ft_select_best_move(stack_a, stack_b);
	}
		ft_rollthatdude(stack_a, stack_b, data);
}
