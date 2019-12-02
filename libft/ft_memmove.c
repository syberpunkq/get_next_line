/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:31:27 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/27 21:21:33 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	const char	*from;
	char		*to;

	if (!(dst || src))
		return (NULL);
	from = (const char *)src;
	to = (char *)dst;
	i = 0;
	if (dst >= src)
	{
		i = len - 1;
		while (i >= 0)
		{
			to[i] = from[i];
			i--;
		}
	}
	else
		while (len--)
			*to++ = *from++;
	return (dst);
}
