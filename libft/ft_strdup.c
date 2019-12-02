/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:44:56 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/26 00:27:35 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int				i;
	int				c;
	unsigned char	*src;
	char			*dst;

	i = 0;
	c = 0;
	src = (unsigned char *)s1;
	while (s1[i])
	{
		c++;
		i++;
	}
	if (!(dst = malloc(sizeof(char) * (c + 1))))
		return (NULL);
	i = 0;
	while (i <= c)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
