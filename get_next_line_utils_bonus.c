/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoayedde <yoayedde@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-15 10:39:16 by yoayedde          #+#    #+#             */
/*   Updated: 2024-11-15 10:39:16 by yoayedde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int check(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *joint(char *s1, char *s2)
{
    int i;
    int j;
    int s1len;
    int s2len;
    char *str;

    i = -1;
    j = -1;
    if (!s1)
        s1len = 0;
    else
        s1len = ft_strlen(s1);
    s2len = ft_strlen(s2);
    str = malloc(s1len + s2len + 1);
    if (!str)
        return (NULL);
    while (++i < s1len)
        str[i] = s1[i];
    while (++j < s2len)
        str[i + j] = s2[j];
    str[i + j] = '\0';
    free(s1);
    return (str);
}

char *fucknewlines(char *str)
{
    int i;
    int j;
    char    *s;

    i = 0;
    j = -1;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    s = malloc(i + 2);
    if (!s)
        return (NULL);
    while (++j < i + 1)
        s[j] = str[j];
    s[j] = '\0';
    return (s);
}

char *leftovers(char *str)
{
    int i;
    int len;
    int j;
    char *s;

    i = 0;
    j = -1;
    len = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    if (str[i] == '\0')
        return (NULL);
    i++;
    while (str[i + len])
        len++;
    s = malloc(len + 1);
    if (!s)
        return (NULL);
    while (++j < len)
        s[j] = str[i + j];
    s[j] = '\0';
    return (s);
}