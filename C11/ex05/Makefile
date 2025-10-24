NAME=do-op
SRC=main.c utils.c ops.c
OBJ=$(SRC:.c=.o)
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJ)
	cc $(CFLAGS) -o $(NAME) $(OBJ)

clean: ; rm -f $(OBJ)
fclean: clean ; rm -f $(NAME)
re: fclean all
