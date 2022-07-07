/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:29:45 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/07 19:51:15 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list *ft_swap_stack(t_list *stack)
{
	t_list *elem;
	
	elem = stack;
	stack = stack->next;
	while (stack)
	{
		stack = stack->next;
		elem = stack->next;
	}
	//ft_swap(&elem->content, &stack->content);
	ft_printstack(stack);
	return (stack);
}