/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:33:19 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/27 01:38:31 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int i;
	int word;
	int result;

	i = 0;
	word = 0;
	result = 0;
	while (s[i])
	{
		if (s[i] != c && !word)
		{
			word = 1;
			result++;
		}
		else if (s[i] == c && word)
			word = 0;
		i++;
	}
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		len;

	if (!(s && c))
		return (NULL);
	if (!(res = malloc(sizeof(char *) * count(s, c) + 1)))
		return (NULL);
	j = 0;
	i = 0;
	while (j < count(s, c))
	{
		while (s[i] == c)
			i++;
		len = 0;
		while (s[i] != c && s[i] != 0)
		{
			len++;
			i++;
		}
		res[j++] = ft_strsub(s, i - len, len);
	}
	res[j] = 0;
	return (res);
}
