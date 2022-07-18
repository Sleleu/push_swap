/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:49 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 07:58:40 by sleleu           ###   ########.fr       */
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
	int	lowmedian;
	int	bigmedian;
	int	pos_low;
	int	index;
}		t_data;

/* PUSH_SWAP */

int		ft_is_sort(t_list *s_a, t_list *s_b);
void	ft_check_arg(char **argv);
void	ft_init_stack(char **argv, t_list **s_a);
void	ft_printstack(t_list *stack);

/* ACTION */

void	ft_swap(int *a, int *b);
void	ft_swap_stack(t_list *stack, int action);
void	ft_push_stack(t_list **dest, t_list **src, int action);
void	ft_rotate(t_list *stack, int action);
void	ft_reverse_rotate(t_list *stack, int action);

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

/* LITTLE ALGO */

void	ft_print_action(int action);
void	ft_algo_two(t_list *s_a);
void	ft_algo_three(t_list *s_a);
void	ft_algo_five(t_list **s_a, t_list **s_b, t_data *data);

/* BIG ALGO */

void	ft_init_sort(t_list **s_a, t_list **s_b, t_data *data);
void	ft_select_best_move(t_list **s_a, t_list **s_b);
void	ft_rollthatdude(t_list **s_a, t_list **s_b, t_data *data);
void	ft_big_algo(t_list **s_a, t_list **s_b, t_data *data);

/* MOVE */

void	ft_move(t_list **s_a, t_list **s_b);
void	ft_down(t_list **stack, char c);
void	ft_up(t_list **stack, char c);
void	ft_db_down(t_list **s_a, t_list **s_b);
void	ft_db_up(t_list **s_a, t_list **s_b);

/* GET DATA */

void	ft_get_data(t_list **s_a, t_data *data);
void	ft_get_median(int *tab, int size, t_data *data);
void	ft_get_tab(t_list **s_a, int *tab, int size);
void	ft_get_min_max(t_list **s_a, t_data *data);

/* UTILS */

void	ft_find_best_a(t_list **s_a, t_list **tmp_a, t_list **tmp_b);
void	ft_is_best(t_list **s_a, t_list **s_b, int *best_move);
int		ft_abs(int i);
int		ft_good_place(t_list **s_a, t_list **s_b, t_list *last);
int		ft_good_a(t_list *tmp_a, t_list *tmp_b);

#endif