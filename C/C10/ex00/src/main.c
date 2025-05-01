#include "ft_display_file.h"

int	ft_display_file(int fd)
{
	char buffer[8192];
	int bytes_read;

	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (bytes_read < 0)
		return (0);
	return (1);
}
int	main(int argc, char **argv)
{
	int fd;
	int result;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		result = ft_display_file(fd);
		if (!result)
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
		close(fd);
	}
	else 
	{
		if (argc == 1)
			write(2, "File name missing.\n", 19);
		else
			write(2, "Too many arguments.\n", 20);
		return (1);
	}
	return (0);
}
