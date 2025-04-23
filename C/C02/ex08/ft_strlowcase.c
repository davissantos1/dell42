char	*ft_strlowcase(char *str)
{
	char *orig;

	orig = str;
	while (*str)	
	{
		if (*str >= 'A' && *str <='Z')
			*str += 32;
		str++;
	}
	return (orig);
}
