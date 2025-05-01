.PHONY: all clean fclean re
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRC_DIR = src
SRC = main.c 
OBJ = $(SRC:.c=.o)
SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_PATH = $(addprefix $(SRC_DIR)/, $(OBJ))
NAME = ft_display_file

all: $(NAME)

$(NAME): $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
