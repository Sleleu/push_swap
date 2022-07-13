/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:54 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/13 21:45:38 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_good_place(t_list **stack_a, t_list **stack_b, t_list *last)
{
	if ((*stack_b)->content < (*stack_a)->content && (*stack_b)->content > last->content)
		return (1);
	return (0);
}

void	big_algo(t_list **stack_a, t_list **stack_b)
{
	int place;
	t_list	*last;

	last = ft_lstlast(*stack_a);
	while ((*stack_a)->next->next)
		ft_push_stack(stack_b, stack_a, PB);
//while (!ft_is_sort(*stack_a, *stack_b))
//{
	ft_printf("\n ----------- STACK A ----------\n");
	ft_printstack(*stack_a);
	ft_printf("\n ----------- STACK B ----------\n");
	ft_printstack(*stack_b);
	ft_printf("\n ----------- LAST VALUE = %d----------\n", last->content);
			place = 0;
	//last = ft_lstlast(*stack_a);
	if (ft_good_place(stack_a, stack_b, last))
		ft_push_stack(stack_a, stack_b, PA);
	else
	{
		last = *stack_a;
		ft_printf("last si ELSE : %d\n", last->content);
		while (last && !ft_good_place(stack_a, stack_b, last))
		{
			printf("%d place", place);
			last = last->next;
			place++;
		}
		if (place < (ft_lstsize(*stack_a) / 2))
		{
			ft_printf("passe dans le if\n");
			while (place >= 0)
			{
				ft_rotate(*stack_a, RA);
				place--;
			}
			ft_push_stack(stack_a, stack_b, PA);
		}
		else
		{
			ft_printf("passe dans le else\n");
			while (((ft_lstsize(*stack_a) / 2) - place) >= 0)
			{
				ft_reverse_rotate(*stack_a, RRA);
				place++;
			}
			ft_push_stack(stack_a, stack_b, PA);
		}
	}
//}
}