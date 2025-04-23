char	*ft_strupcase(char *str)
{
	char *orig;

	orig = str;
	while (*str)
	{
		if (*str >= 'a' && *str <='z')
			*str -= 32;
		str++;
	}
	return (orig);
}
