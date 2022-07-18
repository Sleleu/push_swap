/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:03:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 05:59:50 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_db_up(t_list **s_a, t_list **s_b, int *best_a, int *best_b)
{
	while (*best_b > 0 && *best_a > 0)
	{
		ft_multiple_rotate(s_a, s_b);
		*best_b = *best_b - 1;
		*best_a = *best_a - 1;
	}
}

void	ft_db_down(t_list **s_a, t_list **s_b, int *best_a, int *best_b)
{
	while (*best_b < 0 && *best_a < 0)
	{
		ft_multiple_reverse_rotate(s_a, s_b);
		*best_b = *best_b + 1;
		*best_a = *best_a + 1;
	}
}

void	ft_up(t_list **stack, int *best, char c)
{
	if (c == 'a')
	{
		while (*best > 0)
		{
			ft_rotate(*stack, RA);
			*best = *best - 1;
		}
	}
	else if (c == 'b')
	{
		while (*best > 0)
		{
			ft_rotate(*stack, RB);
			*best = *best - 1;
		}
	}
}

void	ft_down(t_list **stack, int *best, char c)
{
	if (c == 'a')
	{
		while (*best < 0)
		{
			ft_reverse_rotate(*stack, RRA);
			*best = *best + 1;
		}
	}
	else if (c == 'b')
	{
		while (*best < 0)
		{
			ft_reverse_rotate(*stack, RRB);
			*best = *best + 1;
		}
	}
}

void	ft_move(t_list **s_a, t_list **s_b, int best_a, int best_b)
{
	if (best_a > 0 && best_b > 0)
		ft_db_up(s_a, s_b, &best_a, &best_b);
	else if (best_a < 0 && best_b < 0)
		ft_db_down(s_a, s_b, &best_a, &best_b);
	if (best_a > 0)
		ft_up(s_a, &best_a, 'a');
	else if (best_a < 0)
		ft_down(s_a, &best_a, 'a');
	if (best_b > 0)
		ft_up(s_b, &best_b, 'b');
	else if (best_b < 0)
		ft_down(s_b, &best_b, 'b');
}
