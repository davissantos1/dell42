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
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
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
int	ft_base_index(char ch, char *base)
{
	int index;
	
	index = 0;
	while ((base[index] != ch) && base[index])
		index++;
	if (!base[index])
		return (-1);
	return (index);
}
int	ft_convert_int(char *str, char *base, int base_num, int i)
{
	int result;
	int index;
	
	result = 0;
	while (str[i])
	{
		index = ft_base_index(str[i], base);
		if (index == -1)
			break;
		result = result * base_num + index;
		i++;
	}
	return (result);
}
int	ft_atoi_base(char *str, char *base)
{
	int i;
	int signs;
	int result;
	int base_num;

	i = 0;
	result = 0;
	signs = 1;
	base_num = 0;
	if (!(ft_base_check(base)))
		return (0);
	while (base[base_num])
		base_num++;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signs *= -1;
		i++;
	}
	result = ft_convert_int(str, base, base_num, i);
	return (signs * result);
}
