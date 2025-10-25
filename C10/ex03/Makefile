NAME = ft_hexdump
SRC  = main.c hexdump.c hexfmt.c
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