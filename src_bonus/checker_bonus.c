/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:09:31 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/19 00:55:29 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

void	ft_move(t_list **s_a, t_list **s_b, char *action)
{
	if (!ft_strncmp(action, SA, ft_strlen(SA)))
		ft_swap_stack(*s_a);
	else if (!ft_strncmp(action, SB, ft_strlen(SB)))
		ft_swap_stack(*s_b);
	else if (!ft_strncmp(action, PA, ft_strlen(PA)))
		ft_push_stack(s_a, s_b);
	else if (!ft_strncmp(action, PB, ft_strlen(PB)))
		ft_push_stack(s_b, s_a);
	else if (!ft_strncmp(action, RA, ft_strlen(RA)))
		ft_rotate(*s_a);
	else if (!ft_strncmp(action, RB, ft_strlen(RB)))
		ft_rotate(*s_b);
	else if (!ft_strncmp(action, RR, ft_strlen(RR)))
		ft_multiple_rotate(s_a, s_b);
	else if (!ft_strncmp(action, RRA, ft_strlen(RRA)))
		ft_reverse_rotate(*s_a);
	else if (!ft_strncmp(action, RRB, ft_strlen(RRB)))
		ft_reverse_rotate(*s_b);
	else if (!ft_strncmp(action, RRR, ft_strlen(RRR)))
		ft_multiple_reverse_rotate(s_a, s_b);
}

void	ft_checker(t_list **s_a, t_list **s_b)
{
	char	*action;

	while (1)
	{
		action = get_next_line(0);
		if (action == NULL)
			break ;
		ft_move(s_a, s_b, action);
		free(action);
	}
}

int	main(int argc, char **argv)
{
	t_list	*s_a;
	t_list	*s_b;

	s_a = NULL;
	s_b = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	ft_check_arg(argv);
	ft_init_stack(argv, &s_a);
	ft_checker(&s_a, &s_b);
	if (ft_is_sort(s_a, s_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&s_a, free);
	return (0);
}
