/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:43:19 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/15 17:46:58 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_action(int action)
{
	if (action == SA)
		ft_printf("sa\n");
	else if (action == SB)
		ft_printf("sb\n");
	else if (action == SS)
		ft_printf("ss\n");
	else if (action == PA)
		ft_printf("pa\n");
	else if (action == PB)
		ft_printf("pb\n");
	else if (action == RA)
		ft_printf("ra\n");
	else if (action == RB)
		ft_printf("rb\n");
	else if (action == RR)
		ft_printf("rr\n");
	else if (action == RRA)
		ft_printf("rra\n");
	else if (action == RRB)
		ft_printf("rrb\n");
	else if (action == RRR)
		ft_printf("rrr\n");
}

void	ft_algo_two(t_list *stack_a)
{
	ft_swap_stack(stack_a, SA);
}

void	ft_algo_three(t_list *stack_a)
{
	if (stack_a->content < stack_a->next->content)
	{
		if (stack_a->content > stack_a->next->next->content)
			ft_reverse_rotate(stack_a, RRA);
		else if (stack_a->content < stack_a->next->next->content)
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

/*
void	ft_algo_five(t_list **stack_a, t_list **stack_b)
{
	t_list *last;
	int	min;

	min = (*stack_a)->content;
	ft_push_stack(stack_b, stack_a, PB);
	ft_push_stack(stack_b, stack_a, PB);
	ft_algo_three(*stack_a);
	
	while (*stack_b)
	{
		if ((*stack_a)->content > (*stack_b)->content)
			ft_push_stack(stack_a, stack_b, PA);
		else
			ft_rotate(*stack_a, RA);
	}
	ft_printstack(*stack_a);
	last = *stack_a;
	while (last)
	{
		if (last->content < min)
			min = last->content;
		last = last->next;
	}
		ft_printstack(*stack_a);
		last = ft_lstlast(*stack_a);
	while (!ft_is_sort(*stack_a, *stack_b))
	{
		if (last->content == min)
			ft_reverse_rotate(*stack_a, RRA);
		else
			ft_rotate(*stack_a, RA);
	}
}*/