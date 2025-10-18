/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:31:20 by mgee              +#+    #+#             */
/*   Updated: 2025/10/18 11:56:23 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
/* clues: [0..3]=top, [4..7]=bottom, [8..11]=left, [12..15]=right */

int	solve_cell(int grid[4][4], int clues[16], int pos)
{
	int r;
	int c;
	int v;
	int left;
	int right;
	int top;
	int bottom;

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
		if (!row_has_dup(grid, r, c) && !col_has_dup(grid, c, r))
		{
			if (c == 3)
			{
				left = clues[8 + r];
				right = clues[12 + r];
				if (!check_row_views(grid, r, left, right))
				{
					grid[r][c] = 0;
					v++;
					continue ;
				}
			}
			if (r == 3)
			{
				top = clues[c];
				bottom = clues[4 + c];
				if (!check_col_views(grid, c, top, bottom))
				{
					grid[r][c] = 0;
					v++;
					continue ;
				}
			}
			if (solve_cell(grid, clues, pos + 1))
				return (1);
		}
		grid[r][c] = 0;
		v++;
	}
	return (0);
}

/*Purpose
This is the core backtracking algorithm — the puzzle solver.
Algorithm flow
Each cell from 0–15 (4×4 grid) is visited recursively.
For each empty cell:
Try placing values 1–4.
Check for duplicates using row_has_dup & col_has_dup.
If row or column is completed, check visibility clues.
If all checks pass → recurse to next cell.
If no value fits → backtrack (reset to 0).
Success = first valid configuration printed.
“solve.c is a classic depth-first backtracking search.
It tests each possibility systematically but prunes
invalid paths early using the checks and visibility rules.”*/