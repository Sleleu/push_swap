/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:15:17 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/16 00:24:07 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(int error)
{
	if (error == 1)
		ft_printf("ERROR :\nno arguments\n");
	else if (error == 2)
		ft_printf("ERROR :\nstack must have only int\n");
	else if (error == 3)
		ft_printf("ERROR :\nThere is duplicate numbers\n");
	else if (error == 4)
		ft_printf("ERROR :\nBad int value\n");
	exit(EXIT_FAILURE);
}

void	ft_error_no_int(char **argv)
{
	int			i = 1;
	int			j;
	
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

void	ft_error_int_max(char **argv)
{
	int i;
	
	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11)
			ft_error(4);
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			ft_error(4);
		i++;
	}
}

void	ft_error_duplicate(char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	j = i + 1;
	while(argv[i])
	{
		j = i + 1;
		while(argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				ft_error(3);
			j++;
		}
		i++;
	}
}

void	ft_check_arg(char **argv)
{
	ft_error_no_int(argv);
	ft_error_int_max(argv);
	ft_error_duplicate(argv);
}