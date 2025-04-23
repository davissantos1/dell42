#!/bin/sh

LIB_NAME="libft.a"
SRC="ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c"

rm -f *.o $LIB_NAME

for file in $SRC; do
	gcc -Wall -Wextra -Werror -c "$file"
done

ar rcs $LIB_NAME *.o

rm -f *.o
