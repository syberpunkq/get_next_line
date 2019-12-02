/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:45:48 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/26 00:23:31 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*ptr;
	unsigned char	chr;
	unsigned char	*d1;
	unsigned char	*s1;

	d1 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	i = 0;
	ptr = NULL;
	chr = (unsigned char)c;
	while (i < n)
	{
		d1[i] = s1[i];
		if (s1[i] == chr)
			return (d1 + i + 1);
		i++;
	}
	return (ptr);
}
