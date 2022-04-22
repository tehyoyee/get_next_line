/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:40:33 by taehykim          #+#    #+#             */
/*   Updated: 2022/04/22 18:40:35 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	dst_len;
// 	size_t	src_len;

// 	dst_len = ft_strlen(dst);
// 	src_len = ft_strlen(src);
// 	if (dstsize < dst_len + 1)
// 		return (src_len + dstsize);
// 	i = 0;
// 	while (src[i] && dst_len + i + 1 < dstsize)
// 	{
// 		dst[dst_len + i] = src[i];
// 		i++;
// 	}
// 	dst[dst_len + i] = '\0';
// 	return (dst_len + src_len);
// }
// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	src_len;

// 	i = 0;
// 	src_len = 0;
// 	while (src[src_len])
// 		src_len++;
// 	i = 0;
// 	if (dstsize == 0)
// 		return (src_len);
// 	while ((i + 1 < dstsize) && src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (src_len);
// }

// void	*ft_memmove(void *dst, const void *src, size_t n)
// {
// 	size_t	i;

// 	if (!dst && !src)
// 		return (dst);
// 	if (dst < src)
// 	{
// 		i = 0;
// 		while (i < n)
// 		{
// 			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		i = n;
// 		while (i)
// 		{
// 			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
// 			i--;
// 		}
// 	}
// 	return (dst);
// }

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	size_t	i;

// 	if (!dst && !src)
// 		return (dst);
// 	i = 0;
// 	while (i < n)
// 	{
// 		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
// 		i++;
// 	}
// 	return (dst);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*arr;
	size_t	i;
	size_t  j;

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
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		arr[i++] = s2[j++];
	}
	free(s1);
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
