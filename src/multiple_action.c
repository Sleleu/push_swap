/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:34:36 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 05:59:50 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_multiple_rotate(t_list **s_a, t_list **s_b)
{
	ft_rotate(*s_a, RR);
	ft_rotate(*s_b, 0);
}

void	ft_multiple_reverse_rotate(t_list **s_a, t_list **s_b)
{
	ft_reverse_rotate(*s_a, RRR);
	ft_reverse_rotate(*s_b, 0);
}

void	ft_multiple_swap(t_list **s_a, t_list **s_b)
{
	ft_swap_stack(*s_a, SS);
	ft_swap_stack(*s_b, 0);
}
