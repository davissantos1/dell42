#include <unistd.h>

void ft_print_digits(int *arr, int n, int start, int end)
{
    int i = 0;
    while (i < n)
    {
        write(1, &"0123456789"[arr[i]], 1);
        i++;
    }
    if (arr[0] != start || arr[n - 1] != end)
    	write(1, ", ", 2);
}
int	ft_check_shift(int *arr, int n)
{
	int i;
	int j;
	
	i = 0;
	while (i < n)
	{
		j = 0;
    		while (j < n)
    		{
            		if (j != i && arr[i] == arr[j])
                    		return (0);
            		j++;
    		}
		if (arr[i] > 9)
			return (0);
    		i++;
	}
	return (1);
}
int *ft_shift(int *arr, int position, int n)
{
    int i;

    i = position - 1;
    while (i < n)
    {
        if (i == position - 1)
            arr[i]++;
        else
            arr[i] = arr[i - 1] + 1;
        i++;
    }
    if (ft_check_shift(arr, n))
        return arr;
    return ft_shift(arr, position - 1, n);
}
void ft_print_combn_aux(int n, int *arr, int start, int end)
{
    int i;
    int shifted;

    i = 0;
    shifted = 0;
    ft_print_digits(arr, n, start, end);
    if (arr[0] >= start && arr[n - 1] >= end)
        return;
    while (i < n)
    {
        if (arr[i] == 9)
        {
            arr = ft_shift(arr, i, n);
            shifted = 1;
        }
        i++;
    }
    if (!shifted)
        arr[n - 1]++;
    ft_print_combn_aux(n, arr, start, end);
}
void ft_print_combn(int n)
{
    int arr[10];
    int digits;
    int start;
    int end;

    digits = n;
    start = 0;
    end = 9;
    while (digits--)
    {
        arr[start] = start;
        start++;
    }

    start = 10 - n;
    ft_print_combn_aux(n, arr, start, end);
    write(1, "\n", 1);
}
