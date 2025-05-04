CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
LIB_NAME = libft.a
SRC_BIN = srcs
SRC = ft_putchar.c ft_strlen.c ft_putstr.c ft_strcmp.c ft_swap.c
OBJ = $(SRC:.c=.o)
SRC_PATH = $(addprefix $(SRC_BIN)/, $(SRC))
OBJ_PATH = $(addprefix $(SRC_BIN)/, $(OBJ))

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_PATH)
	ar rcs $@ $^

$SRC_BIN/%.o: $(SRC_BIN)/%.c
	$(cc) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ_PATH)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re 
