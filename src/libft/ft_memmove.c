/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:07:47 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/06 14:27:00 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*d;
	const unsigned char		*s;
	int						i;

	d = dst;
	s = src;
	if (d > s)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
/*
   int main(void)
   {
   char    *dst, *src;

   src = strdup("123456");
   dst = strdup("abcdef");
   ft_memmove(dst, src, 4);
   printf("%s\n", dst);
   return (0);
   }
   */
