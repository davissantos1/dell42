#include <unistd.h>

int	main(int argc, char **argv)
{
	int j;
	argc--;
	while (argc >= 1)
	{
		j = 0;
		while(argv[argc][j])
			write(1, &argv[argc][j++], 1);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
