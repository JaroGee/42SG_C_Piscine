/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:52:22 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 11:04:10 by mgee             ###   ########.fr       */
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

void	ft_putnbr(int nb);

static void run(int n, const char *label)
{
	write(1, label, 0);
}

int	main(void)
{
	write(1, "Expect: 0\nGot:    ", 18);
	ft_putnbr(0);
	write(1, "\n", 1);

	write(1, "Expect: 42\nGot:    ", 19);
	ft_putnbr(42);
	write(1, "\n", 1);

	write(1, "Expect: -42\nGot:   ", 20);
	ft_putnbr(-42);
	write(1, "\n", 1);

	write(1, "Expect: 2147483647\nGot:    ", 28);
	ft_putnbr(2147483647);
	write(1, "\n", 1);

	write(1, "Expect: -2147483648\nGot:   ", 28);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
    return (0);
}
*/