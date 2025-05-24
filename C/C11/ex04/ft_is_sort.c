int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;
	int j;
	int asc;
	int des;

	i = 0;
	asc = 0;
	des = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (f(tab[i], tab[j]) > 0)
				des++;
			if (f(tab[i], tab[j]) < 0)
				asc++;

			j++;
		}
		i++;
	}
	if ((asc > 0 && des == 0) || (des > 0 && asc == 0))
		return (1);
	return (0);
}
