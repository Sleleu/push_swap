/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:03:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 06:52:15 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_db_up(t_list **s_a, t_list **s_b)
{
	while ((*s_b)->best > 0 && (*s_a)->best > 0)
	{
		ft_multiple_rotate(s_a, s_b);
		(*s_b)->best--;
		(*s_a)->best--;
	}
}

void	ft_db_down(t_list **s_a, t_list **s_b)
{
	while ((*s_b)->best < 0 && (*s_a)->best < 0)
	{
		ft_multiple_reverse_rotate(s_a, s_b);
		(*s_b)->best++;
		(*s_a)->best++;
	}
}

void	ft_up(t_list **stack, char c)
{
	if (c == 'a')
	{
		while ((*stack)->best > 0)
		{
			ft_rotate(*stack, RA);
			(*stack)->best--;
		}
	}
	else if (c == 'b')
	{
		while ((*stack)->best > 0)
		{
			ft_rotate(*stack, RB);
			(*stack)->best--;
		}
	}
}

void	ft_down(t_list **stack, char c)
{
	if (c == 'a')
	{
		while ((*stack)->best < 0)
		{
			ft_reverse_rotate(*stack, RRA);
			(*stack)->best++;
		}
	}
	else if (c == 'b')
	{
		while ((*stack)->best < 0)
		{
			ft_reverse_rotate(*stack, RRB);
			(*stack)->best++;
		}
	}
}

void	ft_move(t_list **s_a, t_list **s_b)
{
	if ((*s_a)->best > 0 && (*s_b)->best > 0)
		ft_db_up(s_a, s_b);
	else if ((*s_a)->best < 0 && (*s_b)->best < 0)
		ft_db_down(s_a, s_b);
	if ((*s_a)->best > 0)
		ft_up(s_a, 'a');
	else if ((*s_a)->best < 0)
		ft_down(s_a, 'a');
	if ((*s_b)->best > 0)
		ft_up(s_b, 'b');
	else if ((*s_b)->best < 0)
		ft_down(s_b, 'b');
}
