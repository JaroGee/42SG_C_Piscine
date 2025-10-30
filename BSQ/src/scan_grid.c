/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ying <ying@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:34:20 by ying              #+#    #+#             */
/*   Updated: 2025/10/28 23:46:23 by ying             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scan_grid.h"

int	scan_r_c(int r, int c, int k, t_map *map)
{
	int	j;

	j = 0;
	while (j < k)
	{
		if (map->map[k + r][j + c] == map->obstacle)
			return (1);
		if (map->map[j + r][k + c] == map->obstacle)
			return (1);
		j++;
	}
	return (0);
}

int	get_bsq_by_pos(int r, int c, t_map *map)
{
	int	k;

	k = 0;
	while (k + r < map->row && k + c < map->column)
	{
		if (map->map[k + r][k + c] == map->obstacle)
			return (k);
		if (scan_r_c(r, c, k, map))
			return (k);
		k++;
	}
	return (k);
}

void	scan_grid(t_sol *sol, t_map *map)
{
	int	r;
	int	c;
	int	size;

	size = 0;
	r = 0;
	while (r < map->row - sol->size)
	{
		c = 0;
		while (c < map->column - sol->size)
		{
			size = get_bsq_by_pos(r, c, map);
			if (size > sol->size)
			{
				sol->r = r;
				sol->c = c;
				sol->size = size;
			}
			c++;
		}
		r++;
	}
}
