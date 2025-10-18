/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:29:42 by mgee              +#+    #+#             */
/*   Updated: 2025/10/18 11:56:13 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

/* Reject duplicate values in the row prefix [0..upto_c] */
int	row_has_dup(int grid[4][4], int r, int upto_c)
{
	int	used[5];
	int	c;
	int	v;

	used[0] = 0;
	used[1] = 0;
	used[2] = 0;
	used[3] = 0;
	used[4] = 0;
	c = 0;
	while (c <= upto_c)
{
		v = grid[r][c];
	if(v != 0)
{
		if(used[v])
			return(1);
			  used[v] = 1;
		}
		c++;
	}
	return (0);
}

/* Reject duplicate values in the column prefix [0..upto_r] */
int	col_has_dup(int grid[4][4], int c, int upto_r)
{
	int	used[5];
	int	r;
	int	v;

	used[0] = 0;
	used[1] = 0;
	used[2] = 0;
	used[3] = 0;
	used[4] = 0;
	r = 0;
	while (r <= upto_r)
{
		v = grid[r][c];
	if(v != 0)
{
		if(used[v])
			return(1);
		used[v] = 1;
		}
		r++;
	}
	return (0);
}

/*Checks if any duplicates exist in a row or column as we fill the grid.
This prevents invalid placements early (saves recursion time).
Key logic
row_has_dup(grid, r, c)
Builds a small used[5] array (index 1–4)
Marks seen numbers
Returns 1 (true) if a number repeats
col_has_dup works the same but vertically.
Builds a small used[5] array (index 1–4)
Marks seen numbers
Returns 1 (true) if a number repeats
col_has_dup works the same but vertically.*/