/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:52:21 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 10:55:30 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

/*
#include <unistd.h>

void	ft_print_combn(int n);

static void	run(int n)
{
	write(1, "n = ", 4);
	char c = '0' + n;
	write(1, &c, 1);
	write(1, "  ->  ", 6);
	ft_print_combn(n);
	write(1, "\n", 1);
}

int	main(void)
{
	write(1, "Expect n=1 starts: 0, 1, 2, ... 9\nGot:   ", 42);
	ft_print_combn(1);
	write(1, "\n", 1);

	write(1, "Expect n=2 starts: 01, 02, 03, ...\nGot:   ", 43);
	ft_print_combn(2);
	write(1, "\n", 1);

	write(1, "Expect n=3 starts: 012, 013, 014, ...\nGot: ", 45);
	ft_print_combn(3);
	write(1, "\n", 1);

	write(1, "Edge n=9 (should be 123456789 only once):\nGot: ", 48);
	ft_print_combn(9);
	write(1, "\n", 1);

	return (0);
}
*/