/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapdos <mzapdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:35:41 by mzapdos           #+#    #+#             */
/*   Updated: 2019/10/14 23:06:08 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_elem;
	t_list	*prev_elem;
	t_list	*first_elem;

	first_elem = NULL;
	prev_elem = NULL;
	while (lst)
	{
		new_elem = f(lst);
		if (prev_elem)
			prev_elem->next = new_elem;
		else
			first_elem = new_elem;
		prev_elem = new_elem;
		lst = lst->next;
	}
	return (first_elem);
}
