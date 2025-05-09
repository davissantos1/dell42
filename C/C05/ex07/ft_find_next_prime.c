int ft_is_prime(int nb)
{
	int i;

	i = 2;

	if (nb <= 1)
		return (0);
	while (i * i <= nb )
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
int ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	else
		return(ft_find_next_prime(nb + 1));
}
