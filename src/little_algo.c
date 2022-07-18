/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:43:19 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 05:16:40 by sleleu           ###   ########.fr       */
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

void	ft_algo_two(t_list *stack_a)
{
	ft_swap_stack(stack_a, SA);
}

void	ft_reverse_algo_three(t_list *stack_b)
{
	if (stack_b->content > stack_b->next->content)
	{
		if (stack_b->content < stack_b->next->next->content)
			ft_reverse_rotate(stack_b, RRB);
		else if (stack_b->next->content < stack_b->next->next->content)
		{
			ft_reverse_rotate(stack_b, RRB);
			ft_swap_stack(stack_b, SB);
		}
	}
	else
	{
		if (stack_b->next->content > stack_b->next->next->content)
		{
			if (stack_b->content > stack_b->next->next->content)
				ft_swap_stack(stack_b, SB);
			else
				ft_rotate(stack_b, RB);
		}
		else
		{
			ft_swap_stack(stack_b, SB);
			ft_reverse_rotate(stack_b, RRB);
		}
	}
}

void	ft_algo_three(t_list *stack_a)
{
	if (stack_a->content < stack_a->next->content)
	{
		if (stack_a->content > stack_a->next->next->content)
			ft_reverse_rotate(stack_a, RRA);
		else if (stack_a->next->content > stack_a->next->next->content)
		{
			ft_reverse_rotate(stack_a, RRA);
			ft_swap_stack(stack_a, SA);
		}
	}
	else
	{
		if (stack_a->next->content < stack_a->next->next->content)
		{
			if (stack_a->content < stack_a->next->next->content)
				ft_swap_stack(stack_a, SA);
			else
				ft_rotate(stack_a, RA);
		}
		else
		{
			ft_swap_stack(stack_a, SA);
			ft_reverse_rotate(stack_a, RRA);
		}
	}
}

void	ft_algo_five(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while ((*stack_a)->next->next)
	{
		if ((*stack_a)->content == data->min
			|| (*stack_a)->content == data->max)
			ft_rotate(*stack_a, RA);
		else
			ft_push_stack(stack_b, stack_a, PB);
	}
	ft_reverse_algo_three(*stack_b);
	if ((*stack_a)->content == data->min)
		ft_swap_stack(*stack_a, SA);
	while (*stack_b)
		ft_push_stack(stack_a, stack_b, PA);
	ft_reverse_rotate(*stack_a, RRA);
	ft_rollthatdude(stack_a, stack_b, data);
}
