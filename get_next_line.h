#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

char	*make_line(char *buffer, int len, char *line);
char	*get_next_line(int fd);
int		find_nl(char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
#endif