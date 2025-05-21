.PHONY: all re fclean clean 
CC = cc
FLAGS = -Wall -Wextra -Werror -Iincludes
SRC_DIR = src
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
NAME = ft_cat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
