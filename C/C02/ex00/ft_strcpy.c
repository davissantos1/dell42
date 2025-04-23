char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	char	*orig;
	orig = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (orig);
}
