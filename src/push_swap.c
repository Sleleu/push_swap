/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:19 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/07 19:39:49 by sleleu           ###   ########.fr       */
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

void	ft_error(int error)
{
	if (error == 1)
		ft_printf("ERROR :\nno arguments\n");
	else if (error == 2)
		ft_printf("ERROR :\nstack must have only int\n");
	exit(EXIT_FAILURE);
}

void	ft_check_arg(char **argv)
{
	int			i = 1;
	int			j;

	if (argv[1])
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
					ft_error(2);
				j++;
			}
			i++;
		}
	}
}

t_list	*ft_init_stack(char **argv, t_list *stack_a)
{
	int	i = 1;
	int elem;
	t_list *node;
	
	node = stack_a;
	while (argv[i])
	{
		elem = ft_atoi(argv[i]);
		node = ft_lstnew(elem);
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}

void ft_printstack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
//	t_list	*stack_b;

	stack_a = NULL;
//	stack_b = NULL;
	if (argc < 2)
		ft_error(1);
	ft_check_arg(argv);
	stack_a = ft_init_stack(argv, stack_a);
	ft_printstack(stack_a);
	stack_a = ft_swap_stack(stack_a);
	ft_printstack(stack_a);
	return (0);
}
