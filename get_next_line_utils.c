#include "get_next_line.h"

int	check(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*free_em(char	**ptr1, char	**ptr2)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (NULL);
}

char	*duplicate(char	*str)
{
	char	*s;
	int		i;

	i = -1;
	s = malloc(ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	while (str[++i])
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}
