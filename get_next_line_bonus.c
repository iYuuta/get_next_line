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

char *lookforN(char **stash, char **line, int fd)
{
    int bytesread;
    char *buffer;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytesread = read(fd, buffer, BUFFER_SIZE);
    buffer[bytesread] = '\0';
    while (bytesread > 0)
    {
        if (stash && *stash)
            return (free(buffer), fucknewlines(*stash));
        if (check(buffer))
            return (fucknewlines(joint(*stash, buffer)));
    }
}
