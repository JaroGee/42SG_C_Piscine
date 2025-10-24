/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:55:04 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 04:07:20 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:00:00 by student           #+#    #+#             */
/*   Updated: 2025/10/25 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

static int	get_op_index(char c)
{
	if (c == '+')
		return (0);
	if (c == '-')
		return (1);
	if (c == '*')
		return (2);
	if (c == '/')
		return (3);
	if (c == '%')
		return (4);
	return (-1);
}

static int	is_zero_div(char op, int b)
{
	if (op == '/' && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	if (op == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}

static int	apply_op(int idx, int a, int b)
{
	int		(*ops[5])(int, int);

	ops[0] = op_add;
	ops[1] = op_sub;
	ops[2] = op_mul;
	ops[3] = op_div;
	ops[4] = op_mod;
	return (ops[idx](a, b));
}

int	main(int ac, char **av)
{
	int		a;
	int		b;
	int		idx;
	char	op;
	int		res;

	if (ac != 4)
		return (0);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	op = av[2][0];
	if (is_zero_div(op, b))
		return (0);
	idx = get_op_index(op);
	if (idx < 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	res = apply_op(idx, a, b);
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
