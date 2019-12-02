/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:19:53 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/20 21:59:53 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	if (n == 0)
		return (0);
	i = 0;
	d1 = (unsigned char*)s1;
	d2 = (unsigned char*)s2;
	while (i < n && d1[i] == d2[i])
	{
		i++;
	}
	if (i == n)
		i--;
	return ((int)(d1[i] - d2[i]));
}
