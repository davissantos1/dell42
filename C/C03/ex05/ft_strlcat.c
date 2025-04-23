unsigned int ft_strlen(char * str)
{
	unsigned int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int size_src;
	unsigned int size_dest;
	
	i = 0;
	j = 0;
	size_src = ft_strlen(src);
	size_dest = ft_strlen(dest);

	if (size <= size_dest)
		return (size + size_src);
	while (dest[i])
		i++;
	while (src[j] &&  i < size)
		dest[i++] = src[j++];
	dest[i] ='\0';
	return (size_src + size_dest);

}
