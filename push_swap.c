/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:19 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/13 01:14:58 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sort(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstsize(stack_b) != 0)
	{
		//ft_printf("Is not sort yet !\n");
		return (0);
	}
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
		{
			//ft_printf("Is not sort yet !\n");
			return (0);
		}
		stack_a = stack_a->next;
	}
	//ft_printf("Is sort !\n"); // = FIN DU PROGRAMME
	return (1);
}

void	ft_init_stack(char **argv, t_list **stack_a)
{
	int	i = 1;
	int elem;
	t_list *node_a;
	
	node_a = *stack_a;
	while (argv[i])
	{
		elem = ft_atoi(argv[i]);
		node_a = ft_lstnew(elem);
		ft_lstadd_back(stack_a, node_a);
		i++;
	}
}

void ft_printstack(t_list *stack)
{
	t_list *elem;

	elem = stack;
	while (elem)
	{
		ft_printf("%d\n", elem->content);
		elem = elem->next;
	}
		ft_printf("\n ------------- \n");
}

void	ft_algo(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_algo_two(*stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_algo_three(*stack_a);
	(void)stack_b;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		ft_error(1);
	ft_check_arg(argv);
	ft_init_stack(argv, &stack_a);
	if (!ft_is_sort(stack_a, stack_b))
		ft_algo(&stack_a, &stack_b);
	ft_is_sort(stack_a, stack_b);
	return (0);
}

	/*ft_printf ("\n STACK B BEFORE PUSH : \n");
	ft_printstack(stack_b);
	ft_printf ("\n STACK A BEFORE PUSH : \n");
	ft_printstack(stack_a);
	ft_push_stack(&stack_b, &stack_a);
	ft_printf ("\n STACK B AFTER PUSH : \n");
	ft_printstack(stack_b);
	ft_printf ("\n STACK A AFTER PUSH : \n");
	ft_printstack(stack_a);

	ft_printf("\n STACK A BEFORE REVERSE ROTATE : \n");
	ft_printstack(stack_a);
	ft_reverse_rotate(stack_a);
	ft_printf("\n STACK A AFTER REVERSE ROTATE : \n");
	ft_printstack(stack_a);

	ft_printf("\n STACK A BEFORE ROTATE : \n");
	ft_printstack(stack_a);
	ft_rotate(stack_a);
	ft_printf("\n STACK A AFTER ROTATE : \n");
	ft_printstack(stack_a);

	ft_printf("\n STACK A BEFORE SWAP : \n");
	ft_printstack(stack_a);
	ft_swap_stack(stack_a);
	ft_printf("\n STACK A AFTER SWAP : \n");
	ft_printstack(stack_a);*/