unsigned int	ft_strlen(char *str)
{
	unsigned int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}









