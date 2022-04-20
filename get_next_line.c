#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	is_newline(char *buffer);

char	*get_split_line(char **line, int nl)
{
	char	*temp;
	char	*arr;
	// int		len;

	temp = ft_strdup(*line + nl + 2);

	(*line)[nl + 1] = '\0';
	arr = ft_strdup(*line);
	
	// len = ft_strlen(*line + nl + 1);
	// if (len == 0)
	// {
	// 	free(*line);
	// 	*line = 0;
	// 	return (arr);
	// }
	
	// temp = ft_strdup(*line + nl + 1);
	free(*line);
	// *line = NULL;
	*line = temp;
	return (arr);
}

char *get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*arr;
	int			read_size;
	int			nl;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	while ((read_size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		temp = line[fd];
		buffer[read_size] = '\0';
		line[fd] = ft_strjoin(line[fd], buffer);
		free(temp);
		temp = NULL;
		if ((nl = is_newline(line[fd])) >= 0)
		{
			return (get_split_line(&line[fd], nl));
		}
	}

	if (line[fd])
		// for (int i = 0; line[fd][i]; i++)
		// {
		// 	printf("%p\n", &line[fd][i]);
		// }
		nl = is_newline(line[fd]);
	if (line[fd] && nl >= 0)
	{
		return (get_split_line(&line[fd], nl));
	}
	if (line[fd])
	{
		if (ft_strlen(line[fd]))
		{
			arr = ft_strdup(line[fd]);
			free(line[fd]);
			line[fd] = NULL;
			return (arr);
		}
	}
	free(line[fd]);
	line[fd] = NULL;
	// printf("%p\n", line[fd]);

	return (0);
}

// int	main(void)
// {
// 	char	*a;
// 	int	x = open("asdf.txt", O_RDONLY);
// 	for (int i = 0; i < 7; i++)
// 	{
// 		a = get_next_line(x);
// 		// printf("%d gnl = \'%s\'\n", i, a);
// 		free(a);
// 		a = NULL;
// 	}
// 	// printf("1 gnl = %s\n", get_next_line(x));
// 	// printf("2 gnl = %s\n", get_next_line(x));
// 	// printf("3 gnl = %s\n", get_next_line(x));
// 	// printf("4 gnl = %s\n", get_next_line(x));
// 	// printf("5 gnl = %s\n", get_next_line(x));
// 	// printf("6 gnl = %s\n", get_next_line(x));
// 	// printf("7 gnl = %s\n", get_next_line(x));
// 	// printf("8 gnl = %s\n", get_next_line(x));
// 	// printf("9 gnl = %s\n", get_next_line(x));
// 	// system("leaks a.out");
// 	system("leaks a.out | grep leaked");

// }