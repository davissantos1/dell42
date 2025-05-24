int	ft_atoi(char *str)
{
	int i;
	int signs;
	int result;
	
	i = 0;
	signs = 1;
	result = 0;	
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signs *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (signs * result);
}
