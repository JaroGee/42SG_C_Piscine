/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ying <ying@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:39:06 by ying              #+#    #+#             */
/*   Updated: 2025/10/29 00:58:48 by ying             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_input.h"

int	ft_process_header(t_map *map, char *raw_map, int size)
{
	int		i;
	char	*header;

	i = 0;
	header = (char *)malloc((size + 1) * sizeof(char));
	header[size] = '\0';
	while (i < size)
	{
		header[i] = *raw_map;
		if (i == size - 3 && *raw_map >= '0' && *raw_map <= '9')
			return (0);
		raw_map++;
		i++;
	}
	map->row = ft_atoi(header);
	if (header[size - 1] == header[size - 3]
		|| header[size - 2] == header[size - 3]
		|| header[size - 1] == header[size - 2])
		return (0);
	map->empty = header[size - 3];
	map->obstacle = header[size - 2];
	map->full = header[size - 1];
	free(header);
	return (map->row);
}

void	ft_map_row_init(t_map *map, int size)
{
	char	**map_row;

	map->column = size;
	map_row = (char **)malloc((map->row) * sizeof(char *));
	if (!map_row)
	{
		free(map_row);
		map->map = NULL;
		return ;
	}
	map->map = map_row;
}

int	ft_process_map_row(t_map *map, char *raw_map, int size, int curr_row)
{
	int		i;
	char	*map_col;

	i = 0;
	if (curr_row == 0)
		ft_map_row_init(map, size);
	if (!map->map)
		return (0);
	map_col = (char *)malloc((size + 1) * sizeof(char));
	if (!map_col || map->column != size)
		return (0);
	map_col[size] = '\0';
	while (i < size)
	{
		map_col[i] = *raw_map;
		if (!(raw_map[0] == map->empty || raw_map[0] == map->obstacle))
			return (0);
		raw_map++;
		i++;
	}
	map->map[curr_row] = map_col;
	return (i);
}

t_map	*ft_extract_map(char *raw_map)
{
	int		i;
	int		next_line;
	int		row_size;
	int		col_size;
	t_map	*map;

	i = 0;
	row_size = 1;
	col_size = 1;
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	while (*raw_map && i <= row_size)
	{
		next_line = ft_strlen_d(raw_map, "\n");
		if (i == 0)
			row_size = ft_process_header(map, raw_map, next_line);
		else
			col_size = ft_process_map_row(map, raw_map, next_line, i - 1);
		if (row_size < 1 || col_size < 1)
			return (NULL);
		raw_map = raw_map + next_line + 1;
		i++;
	}
	return (map);
}

void	ft_process_map(char *raw_map)
{
	t_map	*map;

	map = ft_extract_map(raw_map);
	if (map == NULL)
	{
		ft_putstr("map error\n");
		ft_free_map(map);
		return ;
	}
	solve_bsq(map);
	print_grid(map);
	ft_free_map(map);
}
