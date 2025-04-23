#include <stdlib.h>
// #include <stdio.h>

char	*ft_strdup(char *str);
int	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);

/*
int	main(void)
{
	char *test = "Hello prick";
	char *test1;

	test1 = ft_strdup(test);
	printf("test - %s\n", test);	
	printf("test1 - %s\n", test1);	
	free(test1);
	return (0);
}
*/

char	*ft_strdup(char *str)
{
	int size;
	char *strdup;
	size = ft_strlen(str);
	strdup = (char *) malloc(sizeof(char) * (size + 1));
	if (!strdup)
		return (0);
	ft_strcpy(strdup, str);
	return(strdup);
}

int	ft_strlen(char *str)
{
	int size;
	
	size = 0;
	while (str[size])
		size++;
		
	return (size);
}

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
