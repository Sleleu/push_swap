/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:03:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/19 00:30:34 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
			ft_rotate(*stack);
			(*stack)->best--;
		}
	}
	else if (c == 'b')
	{
		while ((*stack)->best > 0)
		{
			ft_rotate(*stack);
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
			ft_reverse_rotate(*stack);
			(*stack)->best++;
		}
	}
	else if (c == 'b')
	{
		while ((*stack)->best < 0)
		{
			ft_reverse_rotate(*stack);
			(*stack)->best++;
		}
	}
}
