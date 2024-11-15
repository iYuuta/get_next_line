/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoayedde <yoayedde@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-15 10:38:21 by yoayedde          #+#    #+#             */
/*   Updated: 2024-11-15 10:38:21 by yoayedde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
    static char *stash[OPEN_MAX];
    char        *buffer;
    char *line = NULL;
    int bytesread;
    int         i = 0;
    int         j = 0;
    while (1)
    {
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
        bytesread = read(fd, buffer, BUFFER_SIZE);
        buffer[BUFFER_SIZE] = '\0';
        if (bytesread == -1)
            return (free(buffer), NULL);
        if (bytesread == 0)
        {
            if (stash[fd]){
                line = stash[fd];
                stash[fd] = (NULL);
            }
            return (free(buffer), line);
        }
        else
        {
            if (check(buffer))
            {
                stash[fd] = joint(stash[fd], fucknewlines(buffer));
                line = stash[fd];
                stash[fd] = leftovers(buffer);
                j = 1;
            }
            else
                stash[fd] = joint(stash[fd], buffer);
        }
        buffer = (NULL);
        free(buffer);
        if (j == 1)
            break;
    }
    return (line);
}

// int main()
// {
// 	int a = open("test.txt", O_RDWR);
// 	int b = open("test1.txt", O_RDWR);
// 	int c = open("test2.txt", O_RDWR);
// 	int d = open("test3.txt", O_RDWR);
// 	printf("%s ", get_next_line(a));
//     printf("%s ", get_next_line(b));
//     printf("%s ", get_next_line(c));
//     printf("%s ", get_next_line(d));
//     printf("%s ", get_next_line(a));
//     printf("%s ", get_next_line(b));
//     printf("%s ", get_next_line(c));
//     printf("%s ", get_next_line(d));
//     printf("%s\n", get_next_line(d));
// }