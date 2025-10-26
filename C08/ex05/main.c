/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 03:01:36 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 03:01:36 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c (not to be submitted)
#include <stdlib.h>
#include "ft_stock_str.h"

t_stock_str *ft_strs_to_tab(int ac, char **av);
void        ft_show_tab(struct s_stock_str *par);

int main(int ac, char **av)
{
	t_stock_str *tab = ft_strs_to_tab(ac - 1, av + 1);
	if (!tab) return 1;
	ft_show_tab(tab);
	// free copies
	for (int i = 0; tab[i].str; i++) free(tab[i].copy);
	free(tab);
	return 0;
}

// cc -Wall -Wextra -Werror ft_strs_to_tab.c ft_show_tab.c main.c -o test
// ./test hello "42 SG" rabak
