/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:49 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/17 05:17:25 by sleleu           ###   ########.fr       */
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

typedef struct s_data
{
	int	min;
	int	max;
	int	median;
	int lowmedian;
	int bigmedian;
	int	index;
}		t_data;


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

/* MULTIPLE ACTION */

void	ft_multiple_rotate(t_list **stack_a, t_list **stack_b);
void	ft_multiple_reverse_rotate(t_list **stack_a, t_list **stack_b);
void	ft_multiple_swap(t_list **stack_a, t_list **stack_b);

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
void	ft_algo_five(t_list **stack_a, t_list **stack_b);

/* BIG ALGO */

int		ft_place(t_list **stack_a, t_list **stack_b, t_list *last);
void	ft_init_sort(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_travelator_a(t_list **stack_a, t_list **stack_b, t_list *last, int best_a);
int		ft_travelator_b(t_list **stack_a, t_list **stack_b, int place_b, int place_a);
void	ft_rollthatdude(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_big_algo(t_list **stack_a, t_list **stack_b, t_data *data);

// TEMP

void	ft_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b);

/* GET DATA */

void	ft_get_data(t_list **stack_a, t_data *data);
void	ft_get_median(int *tab, int size, t_data *data);

#endif