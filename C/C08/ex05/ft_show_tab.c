#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);

}
void	ft_show_tab(struct s_stock_str *par)
{
	int i;
	int j;

	i = 0;
	while (par[i].str)
	{
		j = 0;
		while (par[i].str[j])
			write(1, &par[i].str[j++], 1);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		j = 0;
		while (par[i].copy[j])
			write(1, &par[i].copy[j++], 1);
		write(1, "\n", 1);
		i++;
	}
}
