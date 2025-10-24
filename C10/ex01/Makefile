NAME=ft_cat
SRC=main.c
CC=cc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@true

fclean: clean
	rm -f $(NAME)

re: fclean all
