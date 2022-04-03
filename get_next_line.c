#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// ssize_t read (int fd, void *buf, size_t len)



char *get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			len;

	len = 0;
	line = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	len = ft_strlen(buffer);
	line = make_line(buffer, len, line);
	ft_memcpy(buffer, buffer + len, BUFFER_SIZE);
	return line;
}

int	main(void)
{
	int	x = open("asdf.txt", O_RDONLY);
//	get_next_line(x);
//	get_next_line(x);
//	get_next_line(x);
	printf("%s", get_next_line(x));
	printf("%s", get_next_line(x));
	printf("%s", get_next_line(x));
	printf("%s", get_next_line(x));
	printf("%s", get_next_line(x));
	printf("%s", get_next_line(x));
	printf("%s", get_next_line(x));
	printf("%s", get_next_line(x));
	printf("%s", get_next_line(x));
}