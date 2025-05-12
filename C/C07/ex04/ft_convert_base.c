#include <stdlib.h>
// #include <unistd.h>

int	ft_atoi_base(char *str, char *base);
int	ft_base_check(char *base);

int	ft_strlen(char *str)
{
	int size;
	
	size = 0;
	while (str[size])
		size++;
	return (size);
}
int	ft_digit_count(long nbr, int base_num)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr)
	{
		nbr /= base_num;
		count++;
	}
	return (count);
}
char	*ft_itoa_base(long nbr, char *base_to, int digits, char *pt)
{
	int base_num;
	unsigned long int n;
	int i;

	base_num = ft_strlen(base_to);
	pt[digits] = '\0';
	if (nbr < 0)
	{
		i = 1;
		n = -nbr;
	}
	else
	{
		i = 0;
		n = nbr;
	}
	while (digits > i)
	{
		digits--;
		pt[digits] = base_to[n % base_num];
		n /= base_num;
	}
	if (nbr < 0)
		pt[0] = '-';
	return (pt);
}
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int nbr_base_from;
	int base_num;
	char *result;
	int size;

	if (!ft_base_check(base_from) || !ft_base_check(base_to))
		return (NULL);
	nbr_base_from = ft_atoi_base(nbr, base_from);
	base_num = ft_strlen(base_to);
	size = ft_digit_count((long)nbr_base_from, base_num);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result = ft_itoa_base((long)nbr_base_from, base_to, size, result);
	return (result);
}
/*
int	main(void)
{
	char nbr[] = "-101010"; // 42 in binary
	char base_from[] = "01"; 
	char base_to[] = "0123456789abcdef"; // 2a
	char *result = ft_convert_base(nbr, base_from, base_to);
	int i = 0;

	while (result[i])
	{
		write(1, &result[i], 1); 
		i++;
	}
	return (0);
}
*/
