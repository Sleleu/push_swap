/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:19 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 06:08:27 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sort(t_list *s_a, t_list *s_b)
{
	if (ft_lstsize(s_b) != 0)
		return (0);
	while (s_a->next)
	{
		if (s_a->content > s_a->next->content)
			return (0);
		s_a = s_a->next;
	}
	return (1);
}

void	ft_init_stack(char **argv, t_list **s_a)
{
	int		i;
	int		elem;
	t_list	*node_a;

	i = 1;
	node_a = *s_a;
	while (argv[i])
	{
		elem = ft_atoi(argv[i]);
		node_a = ft_lstnew(elem);
		ft_lstadd_back(s_a, node_a);
		i++;
	}
}

void	ft_algo(t_list **s_a, t_list **s_b, t_data *data)
{
	if (ft_lstsize(*s_a) == 2)
		ft_algo_two(*s_a);
	else if (ft_lstsize(*s_a) == 3)
		ft_algo_three(*s_a);
	else if (ft_lstsize(*s_a) == 5)
		ft_algo_five(s_a, s_b, data);
	else
		ft_big_algo(s_a, s_b, data);
}

int	main(int argc, char **argv)
{
	t_list	*s_a;
	t_list	*s_b;
	t_data	data;

	s_a = NULL;
	s_b = NULL;
	if (argc < 2)
		ft_error();
	ft_check_arg(argv);
	ft_init_stack(argv, &s_a);
	ft_get_data(&s_a, &data);
	if (!ft_is_sort(s_a, s_b))
		ft_algo(&s_a, &s_b, &data);
	ft_is_sort(s_a, s_b);
	return (0);
}

/*
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
}*/
