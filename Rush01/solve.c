/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:31:20 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 09:05:45 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

/* clues: [0..3]=top, [4..7]=bottom, [8..11]=left, [12..15]=right */

static int	row_complete_and_ok(int grid[4][4], int clues[16], int r, int c)
{
	int	left;
	int	right;

	if (c != 3)
		return (1);
	left = clues[8 + r];
	right = clues[12 + r];
	return (check_row_views(grid, r, left, right));
}

static int	col_complete_and_ok(int grid[4][4], int clues[16], int r, int c)
{
	int	top;
	int	bottom;

	if (r != 3)
		return (1);
	top = clues[c];
	bottom = clues[4 + c];
	return (check_col_views(grid, c, top, bottom));
}

static int	can_place(int grid[4][4], int clues[16], int r, int c)
{
	if (row_has_dup(grid, r, c))
		return (0);
	if (col_has_dup(grid, c, r))
		return (0);
	if (!row_complete_and_ok(grid, clues, r, c))
		return (0);
	if (!col_complete_and_ok(grid, clues, r, c))
		return (0);
	return (1);
}

int	solve_cell(int grid[4][4], int clues[16], int pos)
{
	int	r;
	int	c;
	int	v;

	if (pos == 16)
		return (1);
	r = pos / 4;
	c = pos % 4;
	if (grid[r][c] != 0)
		return (solve_cell(grid, clues, pos + 1));
	v = 1;
	while (v <= 4)
	{
		grid[r][c] = v;
		if (can_place(grid, clues, r, c))
			if (solve_cell(grid, clues, pos + 1))
				return (1);
		grid[r][c] = 0;
		v++;
	}
	return (0);
}
