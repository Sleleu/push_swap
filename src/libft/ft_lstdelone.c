/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:34:24 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/07 17:15:46 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst)
		return ;
	else
	{
		del(lst->content);
		free(lst);
	}
}
