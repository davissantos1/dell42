#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i;
    int j;
    char table[17];

    i = 0;
    j = 0;

    if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
    }

    while (argv[1][i] != '\0' && j < 17)
	{
        if (argv[1][i] >= '1' && argv[1][i] <= '4') 
		{
			table[j] = argv[1][i];
			write(1, &table[j], 1);
			write(1, " ", 1);
			j++;
        } 
		else if (argv[1][i] != ' ') 
		{
			write(1, "Error\n", 6);
			return (1);
        }
        i++;
    }

    if (j >= 17) 
	{
		write(1, "Error\n", 6);
		return (1);
    }

	return (0);
}
