#include <unistd.h>

void	ft_puthex(unsigned long nbr)
{
	if (nbr > 15)
		ft_puthex(nbr / 16);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
}
void	ft_putstr_position(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] < 32 || str[start] == 127)
			write(1, ".", 1); 
		else
			write(1, &str[start], 1); 
		start++;
	}
}
void	*ft_print_memory(void *addr, unsigned int size)
{
	int i;
	int j;
	void *addr_start;

	i = 0;
	j = 0;
	addr_start = addr;
	addr = (char *)addr;
	while(i < size)
	{
		if (i == 0)
		{
			ft_puthex((unsigned long)addr);
			write(1, ": ", 2);
		}
		ft_puthex(addr[i]);
		if (((i + 1) % 2 == 0) && !(((i + 1) % 16 == 0)))
			write(1, " ", 1);
		if ((i + 1) % 16 == 0 || (i + 1 == size))
		{
			ft_putstr_position(addr_start, j, i);
			j = i;
		}
		if ((i + 1) % 16 == 0)
		{
			write(1, "\n", 1);
			ft_puthex((unsigned long)addr);
		}
		addr++;
		i++;
	}
	return (addr_start);
}

int	main(void)
{
	char *text = "Bonjour les amin ches\n\n\nc\n est fou\ntout\nce qu on peut faire avec\n\n\nprint_memory\n\n\n\nlol\nlol\n \n";
	
	text = ft_print_memory(text, 94);
	return (0);
}
