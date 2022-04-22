#include <stdio.h>

int	main(void)
{
	char	*a;
	int		x = open("asdf.txt", O_RDONLY);

	for (int i = 0; i < 15; i++)
	{
		a = get_next_line(x);
		printf("%d gnl = \'%s\'\n", i, a);
		free(a);
		a = NULL;
	}
	// system("leaks a.out");
	system("leaks a.out | grep leaked");
}