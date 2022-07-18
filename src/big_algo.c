/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:54 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 06:39:00 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_sort(t_list **s_a, t_list **s_b, t_data *data)
{
	while ((*s_a)->next->next->next)
	{
		if ((*s_a)->content == data->min
			|| (*s_a)->content == data->max)
			ft_rotate(*s_a, RA);
		else if ((*s_a)->content < data->lowmedian && data->pos_low > 0)
		{
			ft_rotate(*s_a, RA);
			data->pos_low--;
		}
		else if ((*s_a)->content < data->bigmedian)
			ft_push_stack(s_b, s_a, PB);
		else if ((*s_a)->content > data->bigmedian)
		{
			ft_push_stack(s_b, s_a, PB);
			ft_rotate(*s_b, RB);
		}
		else
			ft_push_stack(s_b, s_a, PB);
	}
	ft_algo_three(*s_a);
}

void	ft_select_best_move(t_list **s_a, t_list **s_b)
{
	int		best_a;
	int		best_b;
	int		best_move;
	t_list	*tmp_a;
	t_list	*tmp_b;

	best_move = 2147483647;
	tmp_b = *s_b;
	(*s_b)->pos = 0;
	while (tmp_b)
	{
		(*s_a)->pos = 0;
		tmp_a = *s_a;
		while (tmp_a->next && !ft_good_a(tmp_a, tmp_b))
		{
			if ((*s_a)->pos == ft_lstsize(*s_a) / 2)
				(*s_a)->pos = (ft_lstsize(*s_a) - (*s_a)->pos) * -1;
			(*s_a)->pos++;
			tmp_a = tmp_a->next;
		}
		if (tmp_a->next && ft_good_a(tmp_a, tmp_b))
			(*s_a)->pos++;
		if (ft_abs((*s_a)->pos) + ft_abs((*s_b)->pos) < ft_abs(best_move))
		{
			best_move = ft_abs((*s_a)->pos) + ft_abs((*s_b)->pos);
			best_b = (*s_b)->pos;
			best_a = (*s_a)->pos;
		}
		if ((*s_b)->pos == ft_lstsize(*s_b) / 2)
			(*s_b)->pos = (ft_lstsize(*s_b) - (*s_b)->pos) * -1;
		(*s_b)->pos++;
		tmp_b = tmp_b->next;
	}
	ft_move(s_a, s_b, best_a, best_b);
}

void	ft_rollthatdude(t_list **s_a, t_list **s_b, t_data *data)
{
	t_list		*tmp;
	static int	place_min = 0;
	static int	place_median = 0;

	tmp = *s_a;
	while (tmp->content != data->min)
	{
		place_min++;
		tmp = tmp->next;
	}
	tmp = *s_a;
	while (tmp->content != data->median)
	{
		place_median++;
		tmp = tmp->next;
	}
	while (!ft_is_sort(*s_a, *s_b))
	{
		if (place_min < place_median)
			ft_rotate(*s_a, RA);
		else
			ft_reverse_rotate(*s_a, RRA);
	}
}

void	ft_big_algo(t_list **s_a, t_list **s_b, t_data *data)
{
	t_list	*last;

	last = ft_lstlast(*s_a);
	ft_init_sort(s_a, s_b, data);
	while (*s_b && !ft_is_sort(*s_a, *s_b))
	{
		last = ft_lstlast(*s_a);
		if (ft_good_place(s_a, s_b, last))
		{
			ft_push_stack(s_a, s_b, PA);
		}
		else
			ft_select_best_move(s_a, s_b);
	}
	ft_rollthatdude(s_a, s_b, data);
}
