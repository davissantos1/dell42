#include <stdlib.h>
// #include <stdio.h>

int	*ft_range(int min, int max);

/*
int	main(void)
{
	int 	min = -4;
	int 	max = 5;
	int	i = 0;
	int	*array = ft_range(min, max);
	
	if (!array)
		return (1);
	
	while (i < max - min)
	{
		printf("%d, ", array[i]);
		i++;
	}
	return(0);
}
*/

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	
	i = 0;
	if (min >= max)
		return (0);	
	range = (int *) malloc(sizeof(int) * (max - min));
	
	if (!range)
		return (0);
	
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
