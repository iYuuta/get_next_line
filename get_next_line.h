/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoayedde <yoayedde@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-12 09:11:48 by yoayedde          #+#    #+#             */
/*   Updated: 2024-11-12 09:11:48 by yoayedde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>

int f_illiteracy(int fd, char **line, char *buffer, char **stash);
char *idkwhatthefuckimdoing(char **stash, char **line, char *buffer);
char *fillstash(int fd, char *line);
char *get_next_line(int fd);
size_t	ft_strlen(char *s);
char *leftovers(char *str);
char *fucknewlines(char *str);
char *joint(char *s1, char *s2);
int check(char *str);

#endif