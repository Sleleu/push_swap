/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:49 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/07 19:38:50 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"

/* PUSH_SWAP */

void	ft_swap(int *a, int *b);
void	ft_error(int error);
void	ft_check_arg(char **argv);
t_list	*ft_init_stack(char **argv, t_list *stack_a);
void	ft_printstack(t_list *stack);

/* SWAP */

t_list *ft_swap_stack(t_list *stack);

/* ROTATE */

/* PUSH */



#endif