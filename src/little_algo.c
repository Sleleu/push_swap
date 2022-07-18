/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:43:19 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 05:59:50 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_action(int action)
{
	if (action == SA)
		write(1, "sa\n", 3);
	else if (action == SB)
		write(1, "sb\n", 3);
	else if (action == SS)
		write(1, "ss\n", 3);
	else if (action == PA)
		write(1, "pa\n", 3);
	else if (action == PB)
		write(1, "pb\n", 3);
	else if (action == RA)
		write(1, "ra\n", 3);
	else if (action == RB)
		write(1, "rb\n", 3);
	else if (action == RR)
		write(1, "rr\n", 3);
	else if (action == RRA)
		write(1, "rra\n", 4);
	else if (action == RRB)
		write(1, "rrb\n", 4);
	else if (action == RRR)
		write(1, "rrr\n", 4);
}

void	ft_algo_two(t_list *s_a)
{
	ft_swap_stack(s_a, SA);
}

void	ft_reverse_algo_three(t_list *s_b)
{
	if (s_b->content > s_b->next->content)
	{
		if (s_b->content < s_b->next->next->content)
			ft_reverse_rotate(s_b, RRB);
		else if (s_b->next->content < s_b->next->next->content)
		{
			ft_reverse_rotate(s_b, RRB);
			ft_swap_stack(s_b, SB);
		}
	}
	else
	{
		if (s_b->next->content > s_b->next->next->content)
		{
			if (s_b->content > s_b->next->next->content)
				ft_swap_stack(s_b, SB);
			else
				ft_rotate(s_b, RB);
		}
		else
		{
			ft_swap_stack(s_b, SB);
			ft_reverse_rotate(s_b, RRB);
		}
	}
}

void	ft_algo_three(t_list *s_a)
{
	if (s_a->content < s_a->next->content)
	{
		if (s_a->content > s_a->next->next->content)
			ft_reverse_rotate(s_a, RRA);
		else if (s_a->next->content > s_a->next->next->content)
		{
			ft_reverse_rotate(s_a, RRA);
			ft_swap_stack(s_a, SA);
		}
	}
	else
	{
		if (s_a->next->content < s_a->next->next->content)
		{
			if (s_a->content < s_a->next->next->content)
				ft_swap_stack(s_a, SA);
			else
				ft_rotate(s_a, RA);
		}
		else
		{
			ft_swap_stack(s_a, SA);
			ft_reverse_rotate(s_a, RRA);
		}
	}
}

void	ft_algo_five(t_list **s_a, t_list **s_b, t_data *data)
{
	while ((*s_a)->next->next)
	{
		if ((*s_a)->content == data->min
			|| (*s_a)->content == data->max)
			ft_rotate(*s_a, RA);
		else
			ft_push_stack(s_b, s_a, PB);
	}
	ft_reverse_algo_three(*s_b);
	if ((*s_a)->content == data->min)
		ft_swap_stack(*s_a, SA);
	while (*s_b)
		ft_push_stack(s_a, s_b, PA);
	ft_reverse_rotate(*s_a, RRA);
	ft_rollthatdude(s_a, s_b, data);
}
