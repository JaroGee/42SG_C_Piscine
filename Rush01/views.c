/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:31:05 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 09:05:14 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	count_visible_forward(const int *v, int len)
{
	int	i;
	int	max;
	int	cnt;

	i = 0;
	max = 0;
	cnt = 0;
	while (i < len)
	{
		if (v[i] > max)
		{
			max = v[i];
			cnt++;
		}
		i++;
	}
	return (cnt);
}

static int	count_visible_backward(const int *v, int len)
{
	int	i;
	int	max;
	int	cnt;

	i = len - 1;
	max = 0;
	cnt = 0;
	while (i >= 0)
	{
		if (v[i] > max)
		{
			max = v[i];
			cnt++;
		}
		i--;
	}
	return (cnt);
}

int	check_row_views(int grid[4][4], int r, int left, int right)
{
	int	tmp[4];
	int	c;

	c = 0;
	while (c < 4)
	{
		tmp[c] = grid[r][c];
		c++;
	}
	if (count_visible_forward(tmp, 4) != left)
		return (0);
	if (count_visible_backward(tmp, 4) != right)
		return (0);
	return (1);
}

int	check_col_views(int grid[4][4], int c, int top, int bottom)
{
	int	tmp[4];
	int	r;

	r = 0;
	while (r < 4)
	{
		tmp[r] = grid[r][c];
		r++;
	}
	if (count_visible_forward(tmp, 4) != top)
		return (0);
	if (count_visible_backward(tmp, 4) != bottom)
		return (0);
	return (1);
}
