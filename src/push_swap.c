/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:19 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/06 19:51:51 by sleleu           ###   ########.fr       */
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

void	ft_get_stack(char **argv, t_list *a)
{
	int	i = 0;
	int elem;
	t_list *node;
	
	while (argv[i])
	{
		elem = ft_atoi(argv[i]);
		node->content = &elem;
		node->next = NULL;
		a->next = ft_lstnew(node->content);
		ft_lstadd_back(&a, node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
//	t_list	*b;
//	int	i;

//	i = 0;
	if (argc < 2)
		ft_error(1);
	ft_check_arg(argv);
	ft_get_stack(argv, a);
/*	while (a[i])
	{
		ft_printf("%d\n", a[i]);
		i++;
	}*/
	return (0);
}
