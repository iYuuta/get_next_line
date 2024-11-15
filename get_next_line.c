/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoayedde <yoayedde@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-12 09:11:46 by yoayedde          #+#    #+#             */
/*   Updated: 2024-11-12 09:11:46 by yoayedde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash;
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
        buffer[bytesread] = '\0';
        //printf("buffer->%s\n", buffer);
        if (bytesread == -1)
            return (free(buffer), NULL);
        if (bytesread == 0)
        {
            if (stash)
            {
                line = stash;
                stash = (NULL);
            }
            return (free(buffer), line);
        }
        else
        {
            if (check(buffer))
            {
                stash = joint(stash, fucknewlines(buffer));
                line = stash;
                stash = leftovers(buffer);
                j = 1;
            }
            else
                stash = joint(stash, buffer);
            if (check(stash))
                stash = leftovers(stash);
        }
        buffer = (NULL);
        free(buffer);
        if (j == 1)
            break;
    }
    return (line);
}

int main()
{
	int a = open("test.txt", O_RDWR);
	int b = open("test1.txt", O_RDWR);
	int c = open("test2.txt", O_RDWR);
	int d = open("test3.txt", O_RDWR);
	for (int i = 0; i < 10; i++)
	    printf("%dLINE:->%s\n",i + 1, get_next_line(a));
}