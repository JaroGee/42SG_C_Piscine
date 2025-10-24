# **************************************************************************** #
# Makefile for ex01 - Build libft.a automatically
# **************************************************************************** #

NAME    := libft.a
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar rc
RLIB    := ranlib

SRC_DIR := srcs
INC_DIR := includes

SRC     := ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS    := $(addprefix $(SRC_DIR)/,$(SRC))
OBJS    := $(SRCS:.c=.o)

# Build everything
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	-$(RLIB) $(NAME)
	@echo "$(NAME) built successfully!"

# Compile each .c file into .o file
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft.h
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Clean .o files
clean:
	rm -f $(OBJS)

# Clean .o files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
