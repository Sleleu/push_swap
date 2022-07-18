/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:10:38 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/19 00:48:39 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

/* CHECKER */

void	ft_move(t_list **s_a, t_list **s_b, char *action);
void	ft_checker(t_list **s_a, t_list **s_b);
void	ft_init_stack(char **argv, t_list **s_a);
int		ft_is_sort(t_list *s_a, t_list *s_b);

/* ACTION */

void	ft_swap(int *a, int *b);
void	ft_swap_stack(t_list *stack);
void	ft_push_stack(t_list **dest, t_list **src);
void	ft_rotate(t_list *stack);
void	ft_reverse_rotate(t_list *stack);

/* MULTIPLE ACTION */

void	ft_multiple_rotate(t_list **s_a, t_list **s_b);
void	ft_multiple_reverse_rotate(t_list **s_a, t_list **s_b);
void	ft_multiple_swap(t_list **s_a, t_list **s_b);

/* ERROR */

void	ft_error(void);
void	ft_error_no_int(char **argv);
void	ft_error_int_max(char **argv);
void	ft_error_duplicate(char **argv);
void	ft_check_arg(char **argv);

/* MOVE */

void	ft_down(t_list **stack, char c);
void	ft_up(t_list **stack, char c);
void	ft_db_down(t_list **s_a, t_list **s_b);
void	ft_db_up(t_list **s_a, t_list **s_b);

#endif