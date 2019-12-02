/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 23:45:37 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/26 00:24:40 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	j = 0;
	result = 0;
	while (dst[i])
		i++;
	while (src[result])
		result++;
	if (size == 0)
		return (result);
	if (size < i)
		result += size;
	else
		result += i;
	while (src[j] && i < size - 1 && dst != src)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = 0;
	return (result);
}
