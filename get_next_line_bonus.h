#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

char	*duplicate(char *str);
void	*free_em(char **ptr1, char **ptr2);
int		ft_strlen(char *str);
int		check(char *str);
char	*get_next_line(int fd);

#endif