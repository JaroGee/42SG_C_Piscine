/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ying <ying@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 01:54:47 by ying              #+#    #+#             */
/*   Updated: 2025/10/28 23:46:28 by ying             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

void	fill_bsq(t_map *map, t_sol *sol)
{
	int	i;
	int	j;

	i = 0;
	while (i < sol->size && (i + sol->r) < map->row)
	{
		j = 0;
		while (j < sol->size && (j + sol->c) < map->column)
		{
			if (map->map[i + sol->r][j + sol->c] == map->empty)
				map->map[i + sol->r][j + sol->c] = map->full;
			j++;
		}
		i++;
	}
}

void	solve_bsq(t_map *map)
{
	t_sol	*sol;

	sol = (t_sol *)malloc(sizeof(t_sol));
	if (!sol)
		return ;
	sol->r = 0;
	sol->c = 0;
	sol->size = 0;
	scan_grid(sol, map);
	fill_bsq(map, sol);
	free(sol);
}
