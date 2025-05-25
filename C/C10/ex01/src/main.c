#include "ft_cat.h"

void	ft_pprogram(char *path)
{
	int i;
	char *prog;
	
	i = 0;
	prog = basename(path);
	while(prog[i])
	{
		write(2, &prog[i], 1);
		i++;
	}
	write(2, ": ", 2);
}
void	ft_perror(int errornum)
{
	char *error_string;
	
	error_string = strerror(errornum);
	while (*error_string)
	{
		write(2, error_string, 1);
		error_string++;
	}
	write(2, "\n", 1);
}
int	ft_read_write(int fd)
{
	char buf[30700];
	int bytes;
	
	errno = 0;
	bytes = (read(fd, buf, 1));
	if (bytes == -1)
		return (errno);
	while (bytes)
	{
		if(write(1, buf, 1) == -1)
			return (errno);
		bytes = (read(fd, buf, 1));
		if (bytes == -1)
			return (errno);
	}
	return (0);
}
int	ft_cat(int argc, char **argv)
{
	int i;
	int fd;
	int error;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			fd = 0;
		else
		{
			errno = 0;
			fd = open(argv[i],O_RDONLY);
			if (fd == -1)
				return (errno);
		}
		error = ft_read_write(fd);
		if (error)
			return (errno);
		if (fd != 0 && close(fd) == -1)
			return (errno);
		i++;
	}
	return(0);
}
int	main(int argc, char **argv)
{
	int error;

	if (argc == 1)
	{	
		error = ft_read_write(0);
		if (error != 0)
		{
			ft_pprogram(argv[0]);
			ft_perror(error);
			return(1);
		}
	}
	else
	{
		error = ft_cat(argc, argv);
		if (error != 0)
		{
			ft_pprogram(argv[0]);
			ft_perror(error);
			return(1);
		}
	}
	return (0);
}
