/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ying <ying@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:40:02 by ying              #+#    #+#             */
/*   Updated: 2025/10/28 21:38:07 by ying             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"

void	cat_content(char *n_r_map, char *r_map, char *buffer, int bytes_read)
{
	int		i;
	int		j;

	i = 0;
	while (r_map[i])
	{
		n_r_map[i] = r_map[i];
		i++;
	}
	j = 0;
	while (j < bytes_read)
	{
		n_r_map[i + j] = buffer[j];
		j++;
	}
}

char	*append_content(char *raw_map, char *buffer, int bytes_read)
{
	char	*new_raw_map;
	int		i;

	i = 0;
	while (raw_map[i])
		i++;
	new_raw_map = (char *)malloc(i + bytes_read + 2);
	if (!new_raw_map)
		return (NULL);
	new_raw_map[i + bytes_read] = '\0';
	new_raw_map[i + bytes_read + 1] = '\0';
	cat_content(new_raw_map, raw_map, buffer, bytes_read);
	free(raw_map);
	return (new_raw_map);
}

void	ft_read_map(int fd)
{
	char	*raw_map;
	char	buffer[BUFFER_SIZE];
	int		bytes_read;

	raw_map = (char *)malloc(1);
	raw_map[0] = '\0';
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		raw_map = append_content(raw_map, buffer, bytes_read);
		if (!raw_map)
		{
			free(raw_map);
			ft_putstr("map error\n");
			return ;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	ft_process_map(raw_map);
	free(raw_map);
}

void	ft_open_map(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("map error\n");
		return ;
	}
	ft_read_map(fd);
	close(fd);
}
