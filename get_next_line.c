#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	int res;
	int last;
	int line_end;
	char *buff;
	char *ptr;
	static char *temp;

	line_end = 0;

	*line = malloc(sizeof(char) * 1);
	buff = malloc(sizeof(char) * BUF_SIZE + 1);
	if (temp)
	{
		// last = ft_strlen(temp);
		if((ptr = ft_strchr(temp, '\n')))
		{
			*ptr = 0;
			*line = ft_strjoin(*line, temp);
			temp = ptr + 1;
			line_end = 1;
		}
		else
		{
			*line = ft_strjoin(*line, temp);
		}
	}
	while (!line_end)
	{
		if ((res = read(fd, buff, BUF_SIZE)) == 0)
			break;
		buff[res] = 0;
		if((ptr = ft_strchr(buff, '\n')))
			{
				*ptr = 0;
				temp = ptr + 1;
				line_end = 1;
			}
		*line = ft_strjoin(*line, buff);
	}
	return(1);
}
