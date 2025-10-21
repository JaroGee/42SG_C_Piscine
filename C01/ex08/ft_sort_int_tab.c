/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:44:02 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 22:51:31 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/*
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int  i = 0;
	int  tab[] = {5, 1, 4, 2, 3};
	int  size = (int)(sizeof(tab) / sizeof(tab[0]));
	char c;

	ft_sort_int_tab(tab, size);

	while (i < size)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		if (i + 1 < size)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
*/