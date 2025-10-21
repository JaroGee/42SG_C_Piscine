/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:29:42 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 09:06:57 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

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
		if (v != 0)
		{
			if (used[v])
				return (1);
			used[v] = 1;
		}
		c++;
	}
	return (0);
}

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
		if (v != 0)
		{
			if (used[v])
				return (1);
			used[v] = 1;
		}
		r++;
	}
	return (0);
}
