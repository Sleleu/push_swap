/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 06:05:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 06:22:25 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_good_place(t_list **s_a, t_list **s_b, t_list *last)
{
	if ((*s_b)->content > last->content
		&& (*s_b)->content < (*s_a)->content)
		return (1);
	return (0);
}

int ft_good_a(t_list *tmp_a, t_list *tmp_b)
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
