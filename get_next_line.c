#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	int res;
	int eof;
	int line_end;
	int temp_len;
	char *buff;
	char *ptr;
	char *foo;
	static char *temp;

	line_end = 0;
    eof = 0;
	buff = malloc(sizeof(char) * BUFF_SIZE + 1);

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	if (!temp)
		temp = ft_strnew(0);
	if ((temp_len = ft_strlen(temp)) != 0)
	{
		if((ptr = ft_strchr(temp, '\n')))
		{
			*ptr = 0;
			foo = ft_strjoin(*line, temp);
			free(*line);
			*line = foo;
			foo = ft_strdup(ptr + 1);
			free(temp);
			temp = foo;
			foo = NULL;
			line_end = 1;
		}
		else
		{
			foo = ft_strjoin(*line, temp);
			free(*line);
			*line = foo;
			foo = NULL;
			ft_memdel((void **) &temp);
		}
	}
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
			ft_memdel((void **) &temp);
			temp = foo;
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
		ft_memdel((void **) &temp);
        return (0);
	}
    else
	    return(1);
}
