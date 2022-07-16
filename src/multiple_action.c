/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:34:36 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/15 23:38:52 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_multiple_rotate(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(*stack_a, RR);
	ft_rotate(*stack_b, 0);
}

void	ft_multiple_reverse_rotate(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(*stack_a, RRR);
	ft_reverse_rotate(*stack_b, 0);
}

void	ft_multiple_swap(t_list **stack_a, t_list **stack_b)
{
	ft_swap_stack(*stack_a, SS);
	ft_swap_stack(*stack_b, 0);	
}