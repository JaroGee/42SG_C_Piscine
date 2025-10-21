/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:52:19 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 10:53:21 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_print_pair(int a, int b)
{
	ft_putchar(a / 10 + '0');
	ft_putchar(a % 10 + '0');
	write(1, " ", 1);
	ft_putchar(b / 10 + '0');
	ft_putchar(b % 10 + '0');
	if (!(a == 98 && b == 99))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_pair(a, b);
			b++;
		}
		a++;
	}
}

/* #include <unistd.h>

void	ft_print_comb2(void);

int	main(void)
{
	write(1, "Expected: 00 01 ... 98 99\nGot: ", 30);
	ft_print_comb2();
	write(1, "\n", 1);
	return (0);
}
*/