# ============ Project ============
NAME    := rush-02

# ============ Toolchain ==========
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Iincludes

# ============ Sources / Objects ===
SRC     := $(wildcard src/*.c)
OBJS    := $(SRC:.c=.o)

# ============ Rules ==============
.PHONY: all clean fclean re run print-vars

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Helper to quickly run a few manual checks after build (optional)
run: all
	./$(NAME) 100 || true
	./$(NAME) 219 || true
	./$(NAME) 1005 || true
	./$(NAME) 1234567 || true

# Debug: see what files make found (optional)
print-vars:
	@echo "SRC = $(SRC)"
	@echo "OBJS = $(OBJS)"