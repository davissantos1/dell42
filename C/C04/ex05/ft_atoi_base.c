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
int	ft_atoi(char *str, char *base, int base_num)
{
	int j;
	int nb;
	int signs;
	int result;

	i = 0;
	result = 0;
	nb = 1;
	signs = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signs *= -1;
		i++;
	}
	while (nb)
	{
		j = 0;
		while (base[j])
		{
			if (str[i] != base[j])
				nb = 0;
			else
				result = result * basenum + (j - 1);
			j++
		}
		i++;

	}
	return (signs * result);
}
int	ft_atoi_base(char *str, char *base);
{
	int base_num;

	base_num = 0;
	if (!(ft_base_check(base)) || (ft_str_check(str, base))
		return (0);
	while (base[base_num])
		base_num++;
	ft_atoi(str, base, base_num);
}
