/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:30:21 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 09:03:27 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putnbr(int n)
{
	char	c;

	c = '0' + n;
	write(1, &c, 1);
}

void	print_grid(int grid[4][4])
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			ft_putnbr(grid[r][c]);
			if (c != 3)
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}
