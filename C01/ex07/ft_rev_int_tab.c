/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:42:49 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 22:51:29 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

/*
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int  i = 0;
	int  tab[] = {1, 2, 3, 4, 5};
	int  size = (int)(sizeof(tab) / sizeof(tab[0]));
	char c;

	ft_rev_int_tab(tab, size);

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