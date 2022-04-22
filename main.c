#include <stdio.h>
#include "get_next_line_bonus.h"
int	main(void)
{
	char	*a;
	char	*b;
	char	*c;
	int		x = open("asdf.txt", O_RDONLY);
	int		y = open("qwer.txt", O_RDONLY);
	int		z = open("zxcv.txt", O_RDONLY);

	for (int i = 0; i < 15; i++)
	{
		a = get_next_line(x);
		b = get_next_line(y);
		c = get_next_line(z);

		printf("%d a's gnl = \'%s\'\n", i, a);
		printf("%d b's gnl = \'%s\'\n", i, b);
		printf("%d c's gnl = \'%s\'\n", i, c);
		free(a);
		a = NULL;
		free(b);
		b = NULL;
		free(c);
		c = NULL;
	}
	// system("leaks a.out");
	system("leaks a.out | grep leaked");
}