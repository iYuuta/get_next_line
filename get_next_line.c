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

char *joinem(char *s1, char *s2)
{
    int i;
    int j;
    size_t s1len;
    size_t s2len;
    char *str;

    i = -1;
    j = -1;
    if (s1 != NULL)
        s1len = ft_strlen(s1);
    else// if s1 == null slen = 0
        s1len = 0;
    s2len = ft_strlen(s2);
    str = malloc(s1len + s2len + 1);
    if (!str)
        return (NULL);
    if (s1){
    while (++i < s1len)
        str[i] = s1[i];
    }
    while (++j < s2len)
        str[i + j] = s2[j];
    str[i + j] = '\0';
    return (str);
}
char *fucknewlines(char *str)
{
    char *s;
    int i = 0;
    int len = 0;

    while (str[len] != '\n' && str[len] != '\0')
        len++;
    if (str[len] != '\n')
        return (NULL);
    s = malloc(len + 1);
    if (!s)
        return (NULL);
    while (i < len)
    {
        s[i] = str[i];
        i++;
    }
    s[i] = '\0';
    return (s);
}
char *leftovers(char *str)
{
    int i = 0;
    int j = 0;
    int len;
    char *s;

    while (str[i] != '\n')
        i++;
    len = ft_strlen(str + i);
    s = malloc(len + 1);
    if (!s)
        return (NULL);
    while (++i < len)
    {
        s[i + j] = str[i];
        i++;
    }
    s[i + j] = '\0';
    return (s);
}
int check(char *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *get_next_line(int fd)
{
    static char *stash;
    char        *line;
    char        *buffer;
    int         i;
    int         k;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    else
        stash = buffer;
    if (!stash)
        stash = strdup("");
    while (1)
    {
        i = 0;
        int a = read(fd, buffer, BUFFER_SIZE);
        if (a == -1)
            return ("read failed");
        buffer[a] = '\0';
        joinem(stash, buffer);
        if (check(stash))
        {
            line = fucknewlines(stash);
            stash = leftovers(stash);
            k = 1;
        }
        if (k == 1)
            break;
    }
    return (line);
}

int main()
{
	int a = open("t.txt", O_RDWR);
	for (int i = 0; i < 6; i++)
	    printf("%d-line->%s\n", i + 1, get_next_line(a));
}