/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:22:14 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/06 14:27:00 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	search;

	search = (unsigned char)c;
	len = ft_strlen(s);
	while (len > 0 && s[len] != search)
		len--;
	if (s[len] == search)
		return ((char *)s + len);
	else
		return (NULL);
}
/*
int	main(void)
{
	const   char *s = "tripouille";
	//int     c = 65;

	printf("%s\n", strrchr(s, 't' + 256));
	printf("%s\n", ft_strrchr(s, 't' + 256));
	return (0);
}*/
