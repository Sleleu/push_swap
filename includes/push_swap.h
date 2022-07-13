/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:49 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/13 02:07:31 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

/* PUSH_SWAP */

int		ft_is_sort(t_list *stack_a, t_list *stack_b);
void	ft_check_arg(char **argv);
void	ft_init_stack(char **argv, t_list **stack_a);
void	ft_printstack(t_list *stack);

/* ACTION */

void	ft_swap(int *a, int *b);
void	ft_swap_stack(t_list *stack, int action);
void	ft_push_stack(t_list **dest, t_list **src, int action);
void	ft_rotate(t_list *stack, int action);
void	ft_reverse_rotate(t_list *stack, int action);

/* ERROR */

void	ft_error(int error);
void	ft_error_no_int(char **argv);
void	ft_error_int_max(char **argv);
void	ft_error_duplicate(char **argv);
void	ft_check_arg(char **argv);

/* LITTLE ALGO */

void	ft_print_action(int action);
void	ft_algo_two(t_list *stack_a);
void	ft_algo_three(t_list *stack_a);

#endif