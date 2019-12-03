/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syberpunkq <syberpunkq@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:10:50 by mzapdos           #+#    #+#             */
/*   Updated: 2019/12/03 22:19:46 by mzapdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstfind(t_list **l_list, int fd)
{
	t_list	*list_elem;
	t_buff	*buff_elem;

	list_elem = *l_list;
	while (list_elem)
	{
		if ((buff_elem = (list_elem)->content) && (buff_elem->fd == fd))
			return (list_elem);
		list_elem = (list_elem)->next;
	}
	buff_elem = (t_buff*)malloc(sizeof(t_buff));
	buff_elem->fd = fd;
	buff_elem->text = ft_strnew(0);
	list_elem = ft_lstnew(buff_elem, sizeof(t_buff));
	free(buff_elem);
	if (*l_list == NULL)
	{
		list_elem->next = NULL;
		*l_list = list_elem;
	}
	else
		ft_lstadd(l_list, list_elem);
	return (list_elem);
}

int		read_from_l_list(t_buff *buff_elem, char **line)
{
	char	*ptr;
	char	*tmp;
	int		line_end;

	line_end = 0;
	if (buff_elem->text && (ft_strlen(buff_elem->text)) != 0)
	{
		if ((ptr = ft_strchr(buff_elem->text, '\n')))
		{
			*ptr = 0;
			ptr = ft_strdup(ptr + 1);
			line_end = 1;
		}
		else
			ptr = ft_strnew(0);
		tmp = ft_strjoin(*line, buff_elem->text);
		free(*line);
		*line = tmp;
		ft_memdel((void **)&(buff_elem->text));
		buff_elem->text = ptr;
	}
	return (line_end);
}

int		read_from_file(char *buff, char **line,
						t_buff *buff_elem, int line_end)
{
	char	*ptr;
	int		res;

	while (!line_end)
	{
		if ((res = read(buff_elem->fd, buff, BUFF_SIZE)) == 0)
			break ;
		buff[res] = 0;
		if ((ptr = ft_strchr(buff, '\n')))
		{
			*ptr = 0;
			ptr = ft_strdup(ptr + 1);
			ft_memdel((void **)&(buff_elem->text));
			buff_elem->text = ptr;
			ptr = NULL;
			line_end = 1;
		}
		ptr = ft_strjoin(*line, buff);
		ft_memdel((void **)line);
		*line = ptr;
		ptr = NULL;
	}
	return (line_end);
}

int		get_next_line(const int fd, char **line)
{
	int				line_end;
	char			*buff;
	static t_list	*l_list;
	t_buff			*buff_elem;
	t_list			*node;

	line_end = 0;
	buff = malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	node = ft_lstfind(&l_list, fd);
	buff_elem = node->content;
	line_end = read_from_l_list(buff_elem, line);
	line_end = read_from_file(buff, line, buff_elem, line_end);
	ft_memdel((void **)&buff);
	if (line_end == 0 && ft_strlen(*line) == 0)
	{
		ft_memdel((void **)line);
		ft_memdel((void **)&(buff_elem->text));
		return (0);
	}
	return (1);
}
