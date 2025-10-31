/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:45:11 by mgee              +#+    #+#             */
/*   Updated: 2025/10/30 15:18:08 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

static void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		printf("[%s]\n", tab[i]);
		i++;
	}
}

static void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(void)
{
	char **tab;

	tab = ft_split("hello,,42|sg|||piscine", ",|");
	print_tab(tab); /* → [hello] [42] [sg] [piscine] */
	free_tab(tab);

	tab = ft_split("  a  b   c  ", " ");
	print_tab(tab); /* → [a] [b] [c] */
	free_tab(tab);

	tab = ft_split("", ",;");
	print_tab(tab); /* → prints nothing */
	free_tab(tab);

	return (0);
}
