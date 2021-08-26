#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;

	src_len = ft_strlen(src);
	j = 0;
	i = ft_strlen(dst);
	if (!dstsize)
		return (src_len);
	if (i > dstsize)
		return (dstsize + src_len);
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + src_len);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		cpy = malloc(1);
		cpy[0] = '\0';
		return (cpy);
	}
	if (s_len < len)
		len = s_len;
	if (s_len - start < len)
		len = s_len - start;
	cpy = malloc(len + 1);
	i = 0;
	if (!cpy)
		return (cpy);
	while (i < len && s[i])
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	return (cpy);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < (int) len)
		{
			((char *) dst)[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			((char *) dst)[i] = ((char *) src)[i];
			i--;
		}
	}
	((char *) dst)[i] = '\0';
	return (dst);
}
