/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ying <ying@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:16:52 by ying              #+#    #+#             */
/*   Updated: 2025/10/28 02:26:23 by ying             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>

struct	s_map_data
{
	int		row;
	int		column;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
};

typedef struct s_map_data	t_map;

struct	s_sol_data
{
	int		r;
	int		c;
	char	size;
};

typedef struct s_sol_data	t_sol;

void	ft_putstr(char *str);

int		ft_atoi(char *str);

int		ft_strlen_d(char *str, char *delimit);

void	ft_putnbr(int nbr, int init);

void	ft_free_map(t_map	*map);