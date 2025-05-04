#include <unistd.h>

void	ft_puthex(unsigned long nbr, int pad)
{
	if (nbr <= 15 && pad == 1)
		write(1, "0", 1);
	if (nbr > 15)
	{
		pad = 0;
		ft_puthex(nbr/16, pad);
	}
	write(1, &"0123456789abcdef"[nbr % 16], 1);
}
void	ft_addrpad(unsigned long nbr, int digits)
{
	if (nbr > 15)
	{
		digits++;
		ft_addrpad(nbr /16, digits);
	}
	if (nbr <= 15)
	{	
		while (digits < 16)
		{
			write(1, "0", 1);
			digits++;
		}
	}
}
void	ft_print_memory_aux(char * c_addr, unsigned int size, int ch)
{
	int j;

	j = 0;
	while (j < ch)
	{
		ft_puthex(c_addr[j], 1);
		j++;
		if (j % 2 == 0)
			write(1, " ", 1);
		if (ch < 16 && j == ch)
		{
			ch = ((16 - ch)/2 + 2*(16 - ch));
			while (ch--)
				write(1, " ", 1);
			ch = size % 16;
		}
	}
	j = 0;
	while (j < ch)
	{
		if (c_addr[j] > 31 && c_addr[j] <= 126)
			write(1, &c_addr[j], 1);
		else
			write(1, ".", 1);
		j++;
	}
}
void	*ft_print_memory(void *addr, unsigned int size)
{
	int ch;
	int lines;
	char *c_addr;

	if (size == 0)
		return ((void *)0);
	else if (size % 16 == 0)
		lines = size / 16;
	else
		lines = (size / 16) + 1;
	ch = 16;
	c_addr = (char *)addr;
	while (lines--)
	{
		if (lines == 0)
			ch = size % 16;
		ft_addrpad((unsigned long)c_addr, 1);
		ft_puthex((unsigned long)c_addr, 1);
		write(1, ": ", 2);
		ft_print_memory_aux(c_addr, size, ch);
		write(1, "\n", 1);
		c_addr += 16;
	}
	return (addr);
}
/*
int main(void)
{
    char data[] = "Bonjour les aminches\n\n\nc\n est fou\ntout\nce qu on peut faire avec\n\n\nprint_memory\n\n\n\nlol\nlol\n \n";
    ft_print_memory(data, 92);
    return (0);
}
*/
