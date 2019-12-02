/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 23:36:36 by mzapdos           #+#    #+#             */
/*   Updated: 2019/09/26 01:19:37 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_count(long i)
{
	int n;

	n = 1;
	while (i >= 10)
	{
		i = i / 10;
		n++;
	}
	return (n);
}

char		*ft_itoa(int i)
{
	int		sign;
	long	nb;
	int		numcount;
	char	*str;

	sign = 0;
	nb = (long)i;
	if (nb < 0 && (nb = -nb))
		sign = 1;
	numcount = num_count(nb) + sign;
	if (!(str = malloc(sizeof(char) * numcount + 1)))
		return (NULL);
	str[numcount--] = '\0';
	if (nb == 0)
		str[numcount] = '0';
	while (nb > 0)
	{
		str[numcount--] = (char)(nb % 10) + 48;
		nb = nb / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
