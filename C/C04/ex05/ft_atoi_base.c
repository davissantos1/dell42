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
	while (base[index] != ch)
		index++;
	return (index);
}
int	ft_str_check(char *str, char* base, int start)
{
	int j;
	int flag;
	
	j = 0;
	flag = 0;
	while (base[j])
	{
		if (str[start] == base[j])
			flag = 1;
		j++;
	}
	return (flag);
}
int	ft_convert_int(char *str, char *base, int base_num, int i)
{
	int j;
	int start;
	int result;
	
	j = 0;
	start = i;
	result = 0;
	while (base[j])
	{
		while ((str[i] == base[j]) && str[i])
		{
			i++;
			j = 0;
		}
		j++;
	}
	if (!ft_str_check(str, base, start))
		return (0);
	while (start < i)
	{
		result = result * base_num + ft_base_index(str[start], base);
		start++;
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
	if (!result)
		return (0);
	return (signs * result);
}
/*
int	main(void)
{
	char data[] = "  ---+--+101010ab567";
	char base[] = "01";
	
	printf("%d\n", ft_atoi_base(data, base));
	return (0);
}
*/
