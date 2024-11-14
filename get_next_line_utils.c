/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoayedde <yoayedde@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-12 09:11:39 by yoayedde          #+#    #+#             */
/*   Updated: 2024-11-12 09:11:39 by yoayedde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *substr(char *str, int index)
{
    char *s;
    int i;
	int j;

	i = 0;
	j = -1;
    while (str[index + i])
        i++;
    s = malloc(i + 1);
    if (!s) return NULL;
    while (++j < i)
	{
        s[j] = str[index + j + 1];
    }
    s[i] = '\0';
    return s;
}