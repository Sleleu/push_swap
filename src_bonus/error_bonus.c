/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:15:17 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/19 00:35:30 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_error_no_int(char **argv)
{
	int			i;
	int			j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9')
				&& argv[i][j] != '-')
				ft_error();
			if (argv[i][j] == '-'
				&& (argv[i][j + 1] < '0' || argv[i][j + 1] > '9'))
				ft_error();
			j++;
		}
		i++;
	}
}

void	ft_error_int_max(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11)
			ft_error();
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			ft_error();
		i++;
	}
}

void	ft_error_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				ft_error();
			j++;
		}
		i++;
	}
}

void	ft_check_arg(char **argv)
{
	if (argv[1][0] == '\0')
		ft_error();
	ft_error_no_int(argv);
	ft_error_int_max(argv);
	ft_error_duplicate(argv);
}
