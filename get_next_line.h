#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*append_to_string(char *s, char *from, int end);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		process_last(char **s, char last[BUFFER_SIZE + 1]);
int		read_to_buffer(char *last, char buffer[BUFFER_SIZE + 1], char **s, int fd);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif // GET_NEXT_LINE_H
