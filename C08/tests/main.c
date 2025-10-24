/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:00:29 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:00:29 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	main(int ac, char **av)
{
	if (ac <= 1)
		return (0);

	t_stock_str	*tab = ft_strs_to_tab(ac - 1, av + 1);
	if (!tab)
		return (1);

	ft_show_tab(tab);

	for (int i = 0; tab[i].str; i++)
		free(tab[i].copy);
	free(tab);
	return (0);
}
