/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:55:03 by mgee              +#+    #+#             */
/*   Updated: 2025/10/22 23:55:05 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

static void	put_line(int x, char left, char mid, char right)
{
	int	i;

	if (x <= 0)
{
		return;
	}
	i = 1;
	while (i <= x)
{
	if(i == 1)
		ft_putchar(left);
		else	if(i == x)
		ft_putchar(right);
		else
		ft_putchar(mid);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	if (x <= 0 || y <= 0)
		return;
	row = 1;
	while (row <= y)
{
	if(row == 1 || row == y)
		put_line(x, 'A', 'B', 'C');
		else
		put_line(x, 'B', ' ', 'B');
		row++;
	}
}
