#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	last[BUFFER_SIZE + 1] = {'\0'};
	char		buffer[BUFFER_SIZE + 1];
	char		*s;

	if (fd < 0 || fd > RLIMIT_NOFILE || BUFFER_SIZE < 1 )
		return (NULL);
	buffer[BUFFER_SIZE] = 0;
	buffer[0] = 0;
	s = NULL;
	if (last[0] != '\0' && process_last(&s, last))
		return (s);
	while (read_to_buffer(last, buffer, &s, fd))
		;
	return (s);
}

int	read_to_buffer(char *last, char buffer[BUFFER_SIZE + 1], char **s, int fd)
{
	int	i;
	int	flag;

	i = 0;
	flag = read(fd, buffer, BUFFER_SIZE);
	if (flag <= 0)
		return (0);
	buffer[flag] = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	*s = append_to_string(*s, buffer, i + 1);
	if (buffer[i] == '\n' && buffer[i + 1])
		ft_memmove(last, &buffer[i + 1], BUFFER_SIZE - i);
	if (buffer[i] == '\n' || i < BUFFER_SIZE)
		return (0);
	return (1);
}

int	process_last(char **s, char last[BUFFER_SIZE + 1])
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (last[i] && last[i] != '\n')
		i++;
	*s = append_to_string(*s, last, i + 1);
	if (last[i] == '\n' && last[i + 1])
	{
		ft_memmove(last, &last[i + 1], ft_strlen(last) - i);
		flag = 1;
	}
	else if (last[i] == '\n')
	{
		last[0] = '\0';
		flag = 1;
	}
	else
		last[0] = '\0';
	return (flag);
}

char	*append_to_string(char *s, char *src, int src_size)
{
	int		i;
	char	*tmp;

	if (s == NULL)
	{
		tmp = malloc(src_size + 1);
		if (!tmp)
			return (NULL);
		tmp[0] = 0;
		ft_strlcat(tmp, src, src_size + 1);
	}
	else
	{
		i = ft_strlen(s);
		tmp = malloc(i + src_size + 1);
		if (!tmp)
			return (NULL);
		tmp[0] = 0;
		ft_strlcat(tmp, s, i + src_size + 1);
		free(s);
		ft_strlcat(tmp, src, i + src_size + 1);
	}
	return (tmp);
}
