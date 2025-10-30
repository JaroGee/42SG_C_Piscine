# **************************************************************************** #
# Makefile for ex01 - Build libft.a automatically
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRC_DIR	= srcs
INC_DIR	= includes

SRCS	= $(addprefix $(SRC_DIR)/, ft_putchar.c ft_swap.c ft_putstr.c \
			ft_strlen.c ft_strcmp.c)
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft.h
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
