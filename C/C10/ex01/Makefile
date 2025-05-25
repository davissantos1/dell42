.PHONY: all re fclean clean 

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes
SRC_DIR = src
SRC = $(SRC_DIR)/main.c
OBJ = $(SRC:.c=.o)
NAME = ft_cat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

