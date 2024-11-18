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


int f_illiteracy(int fd, char **line, char *buffer, char **stash)
{
    int bytesread;

    bytesread = read(fd, buffer, BUFFER_SIZE);
    if (bytesread < 0)
        return (-1);
    if (bytesread == 0)
    {
        if (*stash && **stash)
        {
            *line = joint(*line, *stash);
            *stash = NULL;
        }
        return (0);
    }
    buffer[bytesread] = '\0';
    return (bytesread);
}
char *idkwhatthefuckimdoing(char **stash, char **line, char *buffer)
{
    char *temp;

    temp = *stash;
    if (*stash && check(*stash))
    {
        *line = fucknewlines(*stash);
        *stash = leftovers(*stash);
        free(temp);
        free(buffer);
        return (*line);
    }
    if (check(buffer))
    {
        *line = joint(*stash, fucknewlines(buffer));
        *stash = leftovers(buffer);
        free(buffer);
        return (*line);
    }
    free(buffer);
    return (NULL);
}
char *fillstash(int fd, char *line)
{
    static char *stash;
    int bytesread;
    char *buffer;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (1)
    {
        if (stash && check(stash))
            return(idkwhatthefuckimdoing(&stash, &line, buffer));
        bytesread = f_illiteracy(fd, &line, buffer, &stash);
        if (bytesread == -1)
            return (free(buffer), NULL);
        if (bytesread == 0)
            return (free(buffer), line);
        if (check(buffer))
            return(idkwhatthefuckimdoing(&stash, &line, buffer));
        stash = joint(stash, buffer);
    }
    free(buffer);
    buffer = NULL;
    return (line);
}

char *get_next_line(int fd)
{
    char *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
        return (NULL);
    line = fillstash(fd, line);
    return (line);
}
// void f()
// {
//     system("leaks a.out");
// }
// int main()
// {
//     //atexit(f);
//     int a = open("test.txt", O_RDWR);
    
//     char *s;
//     while ((s = get_next_line(a)))
//     {
//         printf("->%s" , s);
//         free(s);
//     }
// }