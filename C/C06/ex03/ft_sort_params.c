#include <unistd.h>

int	ft_strcmp(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] || b[i])
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
void	ft_swap_ptrs(char **a, char **b)
{
	char *temp;
	
	temp = *a;
	*a = *b;
	*b = temp;

}
void	ft_putstr(char *str)
{
	int i;
	
	i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
void	ft_sort_argv_ptrs(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				ft_swap_ptrs(&argv[i], &argv[j]);
			j++;
		}
		i++;
	}
}
int	main(int argc, char **argv)
{
	int i;
	
	i = 1;
	ft_sort_argv_ptrs(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
