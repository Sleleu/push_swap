/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:34:36 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 21:09:24 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_multiple_rotate(t_list **s_a, t_list **s_b)
{
	ft_rotate(*s_a);
	ft_rotate(*s_b);
}

void	ft_multiple_reverse_rotate(t_list **s_a, t_list **s_b)
{
	ft_reverse_rotate(*s_a);
	ft_reverse_rotate(*s_b);
}

void	ft_multiple_swap(t_list **s_a, t_list **s_b)
{
	ft_swap_stack(*s_a);
	ft_swap_stack(*s_b);
}
