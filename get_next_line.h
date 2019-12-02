#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
int get_next_line(const int fd, char **line);
typedef struct {
  int fd;
  char *text;
} fd_buff;
# define BUFF_SIZE 10

#endif

