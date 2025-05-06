#include <unistd.h>
void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
void	ft_putnbrs(int *sol)
{
	int i;

	i = 0;
	while (i < 10)
	{
		write(1, &"0123456789"[sol[i]], 1);
		i++;
	}
	write(1, "\n", 1);
}
int	ft_solution_check(int *sol)
{
	int i;
	int j;
	
	i = 0;
	while (i < 10)
	{	
		j = i + 1;
		while (j < 10)
		{
			if ((sol[i] == sol[j]))
				return (0);
			if ((sol[i] - sol[j]) == (i - j))
				return (0);
			if ((sol[i] - sol[j]) == (j - i))
				return (0);
			j++;
		}	
		i++;
	}
	return(1);
}
int	ft_solution_solver(int *sol, int start, int end, int counter)
{
	int i;

	if (start == end + 1)
	{
		if (ft_solution_check(sol))
		{
			ft_putnbrs(sol);
			return (1);
		}
		return (0);
	}
	i = start;
	while (i <= end)
	{
		ft_swap(&sol[start], &sol[i]);
		counter += ft_solution_solver(sol, start + 1, end, 0);
		ft_swap(&sol[start], &sol[i]);
		i++;
	}
	return (counter);
}
int	ft_ten_queens_puzzle(void)
{
	int i;
	int sol[10];
	
	i = 0;
	while (i < 10)
	{
		sol[i] = i;
		i++;
	}
	return (ft_solution_solver(sol, 0, 9, 0));
}
/*
int	main(void)
{
	printf("\namount: %d\n", ft_ten_queens_puzzle());
	return (0);
}
*/
