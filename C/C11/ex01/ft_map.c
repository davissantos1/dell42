#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int *result;
	int index;

	index = 0;
	result = (int *)malloc(sizeof(int) * length);
	if (!result)
		return (NULL);
	while (index < length)
	{
		result[index] = f(tab[index]);
		index++;
	}
	return (result);
}
