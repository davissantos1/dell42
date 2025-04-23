#include <unistd.h>

int	main(int argc, char **argv)
{
	char *program;
	(void) argc;

	program = argv[0];
	while (*program)
		write(1, program++, 1);
	write(1, "\n", 1);
	return(0);
}
