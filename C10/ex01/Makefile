NAME = ft_cat
SRC  = main.c cat.c
OBJ  = $(SRC:.c=.o)
CC   = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all