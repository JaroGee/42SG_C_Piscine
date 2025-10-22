/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:20:43 by mgee              +#+    #+#             */
/*   Updated: 2025/10/23 01:21:02 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_put_solution(int pos[10])
{
	char	line[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		line[i] = (char)('0' + pos[i]);
		i++;
	}
	write(1, line, 10);
	write(1, "\n", 1);
}

static int	ft_safe(int pos[10], int col, int row)
{
	int	c;

	c = 0;
	while (c < col)
	{
		if (pos[c] == row)
			return (0);
		if ((pos[c] - row) == (c - col) || (pos[c] - row) == (col - c))
			return (0);
		c++;
	}
	return (1);
}

static void	ft_solve(int pos[10], int col, int *count)
{
	int	row;

	if (col == 10)
	{
		ft_put_solution(pos);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (ft_safe(pos, col, row))
		{
			pos[col] = row;
			ft_solve(pos, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];
	int	count;

	count = 0;
	ft_solve(pos, 0, &count);
	return (count);
}

/*
#include <stdio.h>
int	ft_ten_queens_puzzle(void);

int	main(void)
{
	int total = ft_ten_queens_puzzle();
	printf("Total solutions = %d\n", total);
}
*/