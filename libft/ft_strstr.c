/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 00:56:23 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/27 01:25:46 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;
	char	*from;

	from = (char *)haystack;
	if (!(len = ft_strlen(needle)))
		return (from);
	while ((from = ft_strchr(from, *needle)))
	{
		if (!ft_strncmp(from, needle, len))
			return (from);
		from++;
	}
	return (NULL);
}
