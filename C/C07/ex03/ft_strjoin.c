#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;
	
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char    *ft_strcat(char *dest, char *src)
{
        int i;
        int j;

        i = 0;
        j = 0;
        while (dest[i])
                i++;
	while (src[j])
		dest[i++] = src[j++];
        dest[i] = '\0';
        return (dest);
}
int 	ft_total_size(int size, char **strs, char *sep)
{
	int i;
	int j;
	int sep_size;
	int strs_size;

	i = 0;
	sep_size = 0;
	strs_size = 0;
	while (sep[sep_size])
		sep_size++;
	while (i < size)
	{	
		j = 0;
		while (strs[i][j])
		{
			strs_size++;
			j++;
		}
		i++;
	}
	return (strs_size + (sep_size * (size - 1)));
}
char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int total_size;
	char *result;

	i = 0;
	total_size = ft_total_size(size, strs, sep) + 1; 
	result = (char *) malloc(total_size * sizeof(char));
	if (!result)
		return (NULL);
	if (size == 0)
		return (result);
	while (i < size)
	{
		if (i == 0)
			result = ft_strcpy(result, strs[i]);
		else
			result = ft_strcat(result, strs[i]);
		if (i != size - 1)
			result = ft_strcat(result, sep);
		i++;
	}
	return (result);
}
