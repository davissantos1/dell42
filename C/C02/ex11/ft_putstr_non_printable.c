#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_hexshow(unsigned char nb)
{
	char hex[] = "0123456789abcdef";
	
	ft_putchar(hex[nb / 16]);
	ft_putchar(hex[nb % 16]);
}
void ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str > 31 && *str < 127)
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			ft_hexshow((unsigned char) *str);
		}
		str++;
	}
}
