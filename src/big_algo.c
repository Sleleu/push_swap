/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:54 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/17 05:39:51 by sleleu           ###   ########.fr       */
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
	while ((*stack_a)->next->next)
	{
		if ((*stack_a)->content == data->min || (*stack_a)->content == data->max)
			ft_rotate(*stack_a, RA);
		else if ((*stack_a)->content > data->lowmedian && data->lowmedian > 0)
		{
			ft_push_stack(stack_b, stack_a, PB);
			ft_rotate(*stack_b, RB);	
			data->lowmedian--;
		}
		else if ((*stack_a)->content < data->bigmedian && data->bigmedian > 0)
		{
			ft_rotate(*stack_a, RA);
			data->bigmedian--;
		}
		else if ((*stack_a)->content > data->bigmedian && (*stack_a)->content < data->lowmedian)
			ft_push_stack(stack_b, stack_a, PB);
		else
			ft_push_stack(stack_b, stack_a, PB);
	}
}

void	ft_select_best_move(t_list **stack_a, t_list **stack_b, t_list *last)
{
	//int	i = 0;
	//int j = 0;
	int place_a;
	int place_b;
	int best_a = 2147483647;
	int best_b = 2147483647;
	int best_move;
	t_list	*tmp_a;
	t_list	*tmp_b;
	
	best_move = 2147483647;
	tmp_b = *stack_b;
	place_b = 0;
	while (tmp_b)
	{
		place_a = 0;
	//	j = 0;
		tmp_a = *stack_a;
		while (tmp_a->next && !(tmp_b->content > tmp_a->content && tmp_b->content < tmp_a->next->content))
		{
			//if (place_a > ft_lstsize(*stack_a))
		//		j++;
		//	if (j == 1)
		//		place_a = -place_a;
		//	ft_printf("place a avant %d\n", place_a);
			place_a++;
			tmp_a = tmp_a->next;
		//	ft_printf("place a apres %d\n", place_a);
		}
		if (tmp_a->next && tmp_b->content > tmp_a->content && tmp_b->content < tmp_a->next->content)
			place_a++;
		if (abs(place_a) + abs(place_b) < best_move)
		{
			best_move = place_a + place_b;
			best_b = place_b;
			best_a = place_a;
		}
		tmp_b = tmp_b->next;
		//if (place_b > ft_lstsize(*stack_b))
		//	i++;
		//if (i == 1)
		//	place_b = -place_b;
	//	ft_printf("\n\nplace b avant %d\n", place_b);
			place_b++;
	//	ft_printf("\n\nplace b apres %d\n", place_b);
	//	ft_printf("BEST MOVE A : %d BEST MOVE B %d\n", best_a, best_b);
	}
	//ft_printf("BEST MOVE A : %d BEST MOVE B %d\n", best_a, best_b);
	//ft_travelator_a(stack_a, stack_b, last, best_a);
	best_a = ft_travelator_b(stack_a, stack_b, best_b, best_a);
	ft_travelator_a(stack_a, stack_b, last, best_a);
}

void	ft_travelator_a(t_list **stack_a, t_list **stack_b, t_list *last, int best_a)
{
	(void)last;
	if (best_a < ft_lstsize(*stack_a) / 2)
	{
		while (best_a != 0)
		{
			ft_rotate(*stack_a, RA);
			best_a--;
		}
		ft_push_stack(stack_a, stack_b, PA);
	}
	else
	{
		while (best_a != ft_lstsize(*stack_a))
		{
			ft_reverse_rotate(*stack_a, RRA);
			best_a++;
		}
		ft_push_stack(stack_a, stack_b, PA);
	}
}

int	ft_travelator_b(t_list **stack_a, t_list **stack_b, int place_b, int place_a)
{
	(void)stack_a;
	(void)place_a;
	if (place_b < ft_lstsize(*stack_b) / 2)
	{
		while (place_b > 0)
		{
			if ((place_b <= place_a && place_a < ft_lstsize(*stack_a) / 2))
			{
				place_a--;
				ft_multiple_rotate(stack_a, stack_b);
			}
			else
				ft_rotate(*stack_b, RB);
			place_b--;
		}
	}
	else
	{
		while (place_b != ft_lstsize(*stack_b))
		{
			if (place_b < place_a && place_a > ft_lstsize(*stack_a) / 2)
			{
				ft_multiple_reverse_rotate(stack_a, stack_b);
				place_a++;
			}
			else
				ft_reverse_rotate(*stack_b, RRB);
			place_b++;
		}
	}
	return (place_a);
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
	(void)data;
}

void	ft_big_algo(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*last;

	//	ft_printf("INIT STACK A\n");
	//	ft_printstack(*stack_a);
	last = ft_lstlast(*stack_a);
	ft_init_sort(stack_a, stack_b, data);
	while (*stack_b && !ft_is_sort(*stack_a, *stack_b))
	{
	//	ft_printf("STACK_A\n");
		//ft_printstack(*stack_a);
	//	ft_printf("STACK_B\n");
	//	ft_printstack(*stack_b);
		last = ft_lstlast(*stack_a);
		if (ft_place(stack_a, stack_b, last))
		{
		//	ft_printf("\nbonne place\n");
			ft_push_stack(stack_a, stack_b, PA);
		}
		else
			ft_select_best_move(stack_a, stack_b, last);
	}
		ft_rollthatdude(stack_a, stack_b, data);
		//ft_printf("FINAL STACK A\n");
		//ft_printstack(*stack_a);
		//ft_printf("FINAL STACK_B\n");
	//	ft_printstack(*stack_b);
}
