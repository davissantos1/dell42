void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int start;
	int temp;

	start = 0;
	size--;
	while (start < size)
	{
		temp = tab[start];
		tab[start] = tab[size];
		tab[size] = temp;

		start++;
		size--;
	}
}
