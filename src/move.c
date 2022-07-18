/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:03:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 03:16:17 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_double_up(t_list **stack_a, t_list **stack_b, int *best_a, int *best_b)
{
	while (*best_b > 0 && *best_a > 0)
	{
		ft_multiple_rotate(stack_a, stack_b);
		*best_b = *best_b - 1;
		*best_a = *best_a - 1;
	}
}

void	ft_double_down(t_list **stack_a, t_list **stack_b, int *best_a, int *best_b)
{
	while (*best_b < 0 && *best_a < 0)
	{
		ft_multiple_reverse_rotate(stack_a, stack_b);
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

void	ft_move(t_list **stack_a, t_list **stack_b, int best_a, int best_b)
{
	if (best_a > 0 && best_b > 0)
		ft_double_up(stack_a, stack_b, &best_a, &best_b);
	else if (best_a < 0 && best_b < 0)
		ft_double_down(stack_a, stack_b, &best_a, &best_b);
	if (best_a > 0)
		ft_up(stack_a, &best_a, 'a');
	else if (best_a < 0)
		ft_down(stack_a, &best_a, 'a');
	if (best_b > 0)
		ft_up(stack_b, &best_b, 'b');
	else if (best_b < 0)
		ft_down(stack_b, &best_b, 'b');
}