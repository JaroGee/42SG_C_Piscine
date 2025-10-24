/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:54:35 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:54:39 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	x;

	x = n;
	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		ft_putnbr((int)(x / 10));
	}
	ft_putchar((char)('0' + (x % 10)));
}

int	ft_atoi(const char *s)
{
	long	sign;
	long	res;

	sign = 1;
	res = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
	{
		s++;
	}
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
		{
			sign = -sign;
		}
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = (res * 10) + (*s - '0');
		s++;
	}
	return ((int)(sign * res));
}
