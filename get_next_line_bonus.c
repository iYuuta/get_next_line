#include "get_next_line_bonus.h"

void	joint(char	**old, char	*new, char	*buffer)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while ((*old)[++i] != '\0')
		new[i] = (*old)[i];
	while (buffer[++j] != '\0')
		new[i + j] = buffer[j];
	new[i + j] = '\0';
}

void	leftovers(char	**stash, int index, char	**line)
{
	char	*new;

	new = NULL;
	new = duplicate((*stash) + index);
	if (!new)
	{
		free_em(line, stash);
		return ;
	}
	free_em(stash, NULL);
	*stash = new;
}

void	*fill_stash(char	**stash, char	*buffer)
{
	char	*new;
	int		len;

	new = NULL;
	len = 0;
	if (!(*stash))
	{
		*stash = duplicate(buffer);
		if (!*stash)
			return (free_em(&buffer, NULL));
		return (NULL);
	}
	len = ft_strlen((*stash));
	new = malloc(len + ft_strlen(buffer) + 1);
	if (!new)
		return (free_em(&buffer, stash));
	joint(stash, new, buffer);
	free_em(stash, NULL);
	(*stash) = new;
	return (NULL);
}

char	*fill_line(char	**stash, char	**line, char	**buffer)
{
	size_t	i;
	size_t	size;
	size_t	check;

	check = 0;
	free_em(buffer, NULL);
	if (*stash == NULL || **stash == '\0')
		return (free_em(stash, NULL));
	size = 0;
	i = 0;
	while ((*stash)[size] != '\0' && (*stash)[size] != '\n')
		size++;
	if ((*stash)[size] == '\n')
		check = 1;
	(*line) = malloc(sizeof(char) * (size + check + 1));
	if (!(*line))
		return (free_em(stash, NULL));
	while (i < size + check)
	{
		(*line)[i] = (*stash)[i];
		i++;
	}
	(*line)[i] = '\0';
	leftovers(stash, size + check, line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[OPEN_MAX];
	char		*buffer;
	ssize_t		bytesread;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (free_em(&stash[fd], NULL));
	line = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!check(stash[fd]))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread > 0)
			buffer[bytesread] = '\0';
		else if (bytesread == 0)
			return (fill_line(&stash[fd], &line, &buffer), line);
		else if (bytesread < 0)
			return (free_em(&stash[fd], &buffer));
		fill_stash(&stash[fd], buffer);
	}
	fill_line(&stash[fd], &line, &buffer);
	return (line);
}
