NAME = rush-02

SRC = src/main.c src/str_utils.c src/io_utils.c src/num_validate.c \
      src/dict_lookup.c src/free_all.c src/convert_main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
