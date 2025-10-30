/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ying <ying@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:16:28 by ying              #+#    #+#             */
/*   Updated: 2025/10/29 01:10:19 by ying             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_1.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_atoi(char *str)
{
	int	nbr;

	nbr = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr = nbr + *str - '0';
		str++;
	}
	return (nbr);
}

int	ft_strlen_d(char *str, char *delimit)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (delimit[j])
		{
			if (str[i] == delimit[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_free_map(t_map	*map)
{
	int	i;

	if (map != NULL && map->map != NULL)
	{
		i = 0;
		while (i < map->row)
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
	}
	if (map != NULL)
		free(map);
}
