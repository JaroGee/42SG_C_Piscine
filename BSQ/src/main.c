/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ying <ying@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:41:45 by ying              #+#    #+#             */
/*   Updated: 2025/10/27 21:42:22 by ying             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	int		i;
	int		init;

	if (argc == 1)
	{
		ft_read_map(0);
		return (0);
	}
	i = 1;
	if (argc > 1)
	{
		init = 1;
		while (i < argc)
		{
			if (init == 0)
				ft_putstr("\n");
			init = 0;
			ft_open_map(argv[i]);
			i++;
		}
	}
	return (0);
}
