#include "get_next_line.h"
int get_next_line(const int fd, char **line)
{
	return (read(fd, buf, BUF_SIZE));
}
