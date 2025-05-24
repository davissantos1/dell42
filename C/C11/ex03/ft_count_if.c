int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			counter++;
		i++;
	}
	return (counter);
}
