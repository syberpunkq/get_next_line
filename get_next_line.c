#include "get_next_line.h"

t_list *ft_lstfind(t_list **l_list, int fd)
{
	t_list *new_node;
	fd_buff *buff_elem;
	while(*l_list)
	{
		if((buff_elem = (*l_list)->content) && (buff_elem->fd == fd))
			return(*l_list);
		*l_list = (*l_list)->next;
	}
	buff_elem = (fd_buff*)malloc(sizeof(fd_buff));
	buff_elem->fd = fd;
	buff_elem->text = ft_strnew(0);
	new_node = ft_lstnew(buff_elem, sizeof(fd_buff));
	if (*l_list == NULL)
	{
		new_node->next = NULL;
		*l_list = new_node;
	}
	else
		ft_lstadd(l_list, new_node);
	return(new_node);
}
int read_from_l_list(t_list *l_list, char **line)
{
	int line_end;
	fd_buff *buff_elem;
	char *ptr;
	char *foo;

	line_end = 0;
	buff_elem = l_list->content;
	if ((ft_strlen(buff_elem->text)) != 0)
	{
		if((ptr = ft_strchr(buff_elem->text, '\n')))
		{
			*ptr = 0;
			foo = ft_strjoin(*line, buff_elem->text);
			free(*line);
			*line = foo;
			foo = ft_strdup(ptr + 1);
			free(buff_elem->text);
			buff_elem->text = foo;
			foo = NULL;
			line_end = 1;
		}
		else
		{
			foo = ft_strjoin(*line, buff_elem->text);
			free(*line);
			*line = foo;
			foo = NULL;
			ft_memdel((void **) &(buff_elem->text));
			buff_elem->text = ft_strnew(0);
		}
	}
	return (line_end);
}

int get_next_line(const int fd, char **line)
{
	int res;
	int eof;
	int line_end;
	char *buff;
	char *ptr;
	char *foo;
	// static char *temp;
	static t_list *l_list;
	fd_buff *buff_elem;
	t_list *node;

	line_end = 0;
    eof = 0;
	buff = malloc(sizeof(char) * BUFF_SIZE + 1);

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	node = ft_lstfind(&l_list, fd);
	buff_elem = node->content;
	line_end = read_from_l_list(node, line);

	while (!line_end)
	{
		if ((res = read(fd, buff, BUFF_SIZE)) == 0)
        {
			if(ft_strcmp(*line, "") == 0)
			{
				ft_memdel((void **) line);
				eof = 1;
			}
            break;
        }
		buff[res] = 0;
		if((ptr = ft_strchr(buff, '\n')))
		{
			*ptr = 0;
			foo = ft_strdup(ptr + 1);
			ft_memdel((void **) &(buff_elem->text));
			buff_elem->text = foo;
			foo = NULL;
			line_end = 1;
		}
		foo = ft_strjoin(*line, buff);
		ft_memdel((void **) line);
		*line = foo;
		foo = NULL;
	}
	ft_memdel((void **) &buff);
    if (eof)
	{
		ft_memdel((void **) &(buff_elem->text));
        return (0);
	}
    else
	    return(1);
}
