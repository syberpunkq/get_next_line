/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:16:23 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/26 23:18:01 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*from;

	i = 0;
	from = (const char*)s;
	while (i < n)
	{
		if (from[i] == (char)c)
			return ((void*)&from[i]);
		i++;
	}
	return (NULL);
}
