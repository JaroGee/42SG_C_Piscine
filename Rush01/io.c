/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:30:21 by mgee              +#+    #+#             */
/*   Updated: 2025/10/18 11:30:21 by mgee             ###   ########.fr       */
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

void	ft_putnbr(int n) /* 1..9 only in this project */
{
	char c;

	c = '0' + n;
	write(1, &c, 1);
}

void	print_grid(int grid[4][4])
{
	int r;
	int c;

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

/*Purpose
Handles all output, using only write() (no printf).
Functions
ft_putchar → writes a single character.
ft_putstr → writes a string.
ft_putnbr → writes a single-digit number (1–9 safe).
print_grid → prints the final 4×4 grid, space-separated, newline per row.
Usage
Called by main.c to output the solved grid or error messages.
We don’t use printf because it’s not allowed.
These helpers build everything with write()
which gives full control over spacing and newlines.
*/