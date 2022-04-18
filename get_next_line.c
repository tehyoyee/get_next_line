#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// ssize_t read (int fd, void *buf, size_t len)
int	is_newline(char *buffer);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char *get_next_line(int fd)
{
	static char	*line[1000];
	char		buffer[BUFFER_SIZE + 1];
	char		*arr;
	int			len;
	int			read_size;
	int			nl;
	char		*temp;

	len = 0;


	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while ((read_size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_size] = '\0';
		line[fd] = ft_strjoin(line[fd], buffer);
		if ((nl = is_newline(line[fd])) >= 0)
		{
			line[fd][nl] = '\0';
			arr = ft_strdup(line[fd]);
			temp = ft_strdup(line[fd] + nl + 1);
			free(line[fd]);
			line[fd] = NULL;
			line[fd] = temp;
			free(temp);
			temp = NULL;
			return (arr);
		}
	}
	if (line[fd])
	{
		temp = ft_strdup(line[fd]);
		free(line[fd]);
		line[fd] = NULL;
		return (temp);
	}
	return (0);
}

int	main(void)
{
	int	x = open("asdf.txt", O_RDONLY);
//	get_next_line(x);
//	get_next_line(x);
//	get_next_line(x);
	printf("gnl = %s\n\n", get_next_line(x));
	printf("gnl = %s\n\n", get_next_line(x));
	printf("gnl = %s\n\n", get_next_line(x));
	// printf("gnl = %s\n\n", get_next_line(x));
	// printf("gnl = %s\n\n", get_next_line(x));
	// printf("gnl = %s\n\n", get_next_line(x));
	// printf("gnl = %s\n\n", get_next_line(x));
	// printf("gnl = %s\n\n", get_next_line(x));
	// printf("gnl = %s\n\n", get_next_line(x));
	// printf("gnl = %s\n\n", get_next_line(x));
	// printf("gnl = %s\n\n", get_next_line(x));
	// printf("gnl = %s\n\n", get_next_line(x));
	system("leaks a.out | grep leaked");
}