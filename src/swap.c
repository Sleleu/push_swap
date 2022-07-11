/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:29:45 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/11 22:27:56 by sleleu           ###   ########.fr       */
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

void	ft_swap_stack(t_list *stack)
{
	t_list	*elem1;
	t_list	*elem2;
	
	elem1 = stack;
	elem2 = stack->next;
	ft_swap(&elem1->content, &elem2->content);
}


void	ft_push_stack(t_list **dest, t_list **src)
{
	t_list *elem;
	t_list *previous;
	
	previous = *src;
	if (!(*src))
		return ;
	elem = *src;
	elem = ft_lstnew(elem->content);
	ft_lstadd_front(dest, elem);
	*src = (*src)->next;
	free(previous);
}

void	ft_rotate(t_list *stack)
{
	t_list *elem1;
	t_list *elem2;
	
	elem1 = stack;
	elem2 = stack->next;
	while (elem2)
	{
		ft_swap(&elem1->content, &elem2->content);
		elem1 = elem1->next;
		elem2 = elem2->next;
		
	}
}

void	ft_reverse_rotate(t_list *stack)
{
	t_list *elem1;
	t_list *elem2;
	
	elem1 = stack;
	elem2 = stack;
	while (elem2)
	{
		ft_swap(&elem1->content, &elem2->content);
		elem2 = elem2->next;
	}
}

/* VERSION TENTATIVE SANS LSTNEW ET FREE
void	ft_push_stack(t_list **dest, t_list **src, t_list *node)
{
//	t_list *previous;
	
	if (!(*src)->content)
		return ;
	ft_lstadd_front(dest, *src);
	node = node->next;
	*src = node;
//	*src = previous;
//	previous = NULL;
//	(void)previous;
}*/