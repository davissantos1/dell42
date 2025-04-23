#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);
/*
int	main(void)
{
	int **range;
	int min = -4;
	int max = 5;
	int result;	

	result = ft_ultimate_range(range, min, max);
	printf("%d\n", result);
	
	while ()
	{	
		printf("", 
	}

	return (0);
}
*/

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *) malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;	
	}

	return (max - min);
}

