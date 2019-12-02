/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:28:28 by mzapdos           #+#    #+#             */
/*   Updated: 2019/10/14 23:11:36 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *item;

	if (!(item = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		item->content_size = 0;
		item->content = NULL;
	}
	else
	{
		item->content_size = content_size;
		if (!(item->content = malloc(sizeof(char) * content_size)))
			return (NULL);
		item->content = ft_memcpy(item->content, content, content_size);
	}
	item->next = NULL;
	return (item);
}
