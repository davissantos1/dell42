//#include <unistd.h>
/*
void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr/10);
	write(1, &"0123456789"[nbr % 10], 1);
}
*/
void ft_foreach(int *tab, int length, void(*f)(int))
{
	int i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
int	main(void)
{
	int tab[] = {10, 2, 5, 3};
	ft_foreach(tab, 4, ft_putnbr);
	return (0);
}
*/
