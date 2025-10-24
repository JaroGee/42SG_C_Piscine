#!/bin/bash
set -e

cc -Wall -Wextra -Werror -c \
  ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

ar rc libft.a \
  ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

# ranlib is harmless on systems that don’t need it
ranlib libft.a 2>/dev/null || true

echo "Created libft.a"
