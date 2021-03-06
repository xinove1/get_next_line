/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <thomas.sircus@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:42:35 by nthomas-          #+#    #+#             */
/*   Updated: 2021/08/26 19:49:58 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	clear_last(t_last **lasts, int fd)
{
	t_last	*tmp;
	t_last	*clear;

	if (!*lasts)
		return ;
	clear = *lasts;
	tmp = NULL;
	while (clear->fd != fd && clear->next)
	{
		tmp = clear;
		clear = clear->next;
	}
	if (clear->fd == fd)
	{
		if (clear == *lasts)
			*lasts = clear->next;
		if (tmp)
			tmp->next = clear->next;
		free(clear);
	}
}
