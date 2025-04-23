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
int	ft_strlen(char *str)
{
	int size;
	
	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	ft_strs_to_tab_aux(int ac, char **av, int i, t_stock_str *result)
{
	int size;

	while (i < ac)
	{	
		size = ft_strlen(av[i]);
		result[i].size = size;
		result[i].str = (char *) malloc((size + 1) * sizeof(char));
		result[i].copy = (char *) malloc((size + 1) * sizeof(char));
		if (!result[i].str || !result[i].copy)
		{
			while (i--)
			{
				free(result[i].str);	
				free(result[i].copy);	
			}
			return (0);
		}
		result[i].str = ft_strcpy(result[i].str, av[i]);
		result[i].copy = ft_strcpy(result[i].copy, av[i]);
		i++;
	}
	return (1);
}
struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int i;
	t_stock_str *result;

	i = 0;
	result = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	if (!result)
		return (NULL);
	if (!ft_strs_to_tab_aux(ac, av, i, result))
	{
		free(result);
		return (NULL);
	}
	result[ac].str = NULL;
	result[ac].copy = NULL;
	result[ac].size = 0;
	return (result);
}
