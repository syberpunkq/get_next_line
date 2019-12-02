/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:34:07 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/27 22:08:40 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	start;
	char	*res;

	if (!s)
		return (NULL);
	res = ft_strnew(1);
	start = 0;
	end = ft_strlen(s) - 1;
	while (ft_isspace(s[start]))
		start++;
	if (!s[start])
		return (res);
	while (ft_isspace(s[end]))
		end--;
	if ((end - start) > 0)
		res = ft_strsub(s, start, end - start + 1);
	return (res);
}
