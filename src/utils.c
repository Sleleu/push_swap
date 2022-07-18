/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 06:05:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 07:57:04 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_find_best_a(t_list **s_a, t_list **tmp_a, t_list **tmp_b)
{
	while ((*tmp_a)->next && !ft_good_a(*tmp_a, *tmp_b))
	{
		if ((*s_a)->pos == ft_lstsize(*s_a) / 2)
			(*s_a)->pos = (ft_lstsize(*s_a) - (*s_a)->pos) * -1;
		(*s_a)->pos++;
		*tmp_a = (*tmp_a)->next;
	}
}

void	ft_is_best(t_list **s_a, t_list **s_b, int *best_move)
{
		*best_move = ft_abs((*s_a)->pos) + ft_abs((*s_b)->pos);
		(*s_b)->best = (*s_b)->pos;
		(*s_a)->best = (*s_a)->pos;
}

int	ft_good_place(t_list **s_a, t_list **s_b, t_list *last)
{
	if ((*s_b)->content > last->content
		&& (*s_b)->content < (*s_a)->content)
		return (1);
	return (0);
}

int	ft_good_a(t_list *tmp_a, t_list *tmp_b)
{
	if ((tmp_b->content > tmp_a->content
			&& tmp_b->content < tmp_a->next->content))
		return (1);
	return (0);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	else
		return (i);
}
