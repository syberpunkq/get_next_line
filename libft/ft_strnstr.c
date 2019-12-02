/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:30:26 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/27 22:10:50 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2len;

	if (!*s2)
		return ((char *)s1);
	s2len = ft_strlen(s2);
	while (*s1 && n >= s2len)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, s2len) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
