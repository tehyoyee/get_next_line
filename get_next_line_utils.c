#include "get_next_line.h"

char	*make_line(char *buffer, int len, char *line)
{
	int		i;
	char	*result;

	i = 0;
	if (buffer[i] == '\0')
		return (0);
	free(line);
	line = 0;
	line = (char *)malloc(sizeof(char) * (len + 1));
	while (buffer[i] != '\0')
	{
		line[i] = buffer[i];
		if (line[i] == '\n')
		{
			line[++i] = '\0';
			return (line);
		}
		i++;		
	}
	line[i] = '\0';
	return (line);
}

size_t	ft_strlen(const char *s)
{
	int	result;

	result = 0;
	while (*s != '\n')
	{
		if (*s == '\0')
			return (result);
		result++;
		s++;
	}
	result++;
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while ((i + 1 < dstsize) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i)
		{
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*arr;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s1)
		arr[i++] = *s1++;
	while (*s2)
		arr[i++] = *s2++;
	arr[i] = '\0';
	return (arr);
}
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*arr;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	arr = (char *)malloc(sizeof(char) * i + 1);
	if (!arr)
		return (NULL);
	arr[i] = '\0';
	i--;
	while (i >= 0)
	{
		arr[i] = s1[i];
		i--;
	}
	return (arr);
}
