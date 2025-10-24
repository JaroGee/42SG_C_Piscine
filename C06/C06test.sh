#!/bin/sh
set -e

echo "== ex00 =="
cc ex00/ft_print_program_name.c -Wall -Wextra -Werror -o ex00.out
./ex00.out | cat -e

echo "== ex01 =="
cc ex01/ft_print_params.c -Wall -Wextra -Werror -o ex01.out
./ex01.out hello "42 SG" test | cat -e

echo "== ex02 =="
cc ex02/ft_rev_params.c -Wall -Wextra -Werror -o ex02.out
./ex02.out hello "42 SG" test | cat -e

echo "== ex03 =="
cc ex03/ft_sort_params.c -Wall -Wextra -Werror -o ex03.out
./ex03.out zebra Apple apple 42 _abc | cat -e
