/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 00:50:04 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/18 09:48:41 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_min_max(t_list **s_a, t_data *data)
{
	int		min;
	int		max;
	t_list	*tmp;

	tmp = *s_a;
	min = (*s_a)->content;
	max = (*s_a)->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	data->min = min;
	data->max = max;
}

void	ft_get_tab(t_list **s_a, int *tab, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *s_a;
	while (i < size)
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
}

void	ft_get_median(int *tab, int size, t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] < tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	k = i / 3;
	l = k * 2;
	i = i / 2;
	data->pos_low = k;
	data->median = tab[i];
	data->lowmedian = tab[l];
	data->bigmedian = tab[k];
}

void	ft_get_data(t_list **s_a, t_data *data)
{
	int		*tab;
	int		i;
	int		size;
	t_list	*tmp;

	i = 0;
	tmp = *s_a;
	size = ft_lstsize(*s_a);
	tab = malloc(sizeof(int *) * size);
	if (!tab)
		exit(EXIT_FAILURE);
	while (i < size)
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	ft_get_min_max(s_a, data);
	ft_get_tab(s_a, tab, size);
	ft_get_median(tab, size, data);
	free(tab);
}
