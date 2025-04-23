#include <unistd.h>

int	ft_base_check(char *base)
{
	int i;
	int j;

	i = 0;
	if (!(base) || !(base[0]) ||!(base[1])) 
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while(base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
void	ft_putnbr(long int nbr, char *base, int base_num)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > base_num - 1)
		ft_putnbr(nbr / base_num, base, base_num);
	write(1, &base[nbr % base_num], 1);

}
void	ft_putnbr_base(int nbr, char *base)
{
	int base_num;

	base_num = 0;
	if (!(ft_base_check(base)))
		return;
	while (base[base_num])
		base_num++;
	ft_putnbr( (long int) nbr, base, base_num);
}
