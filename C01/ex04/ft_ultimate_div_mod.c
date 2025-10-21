/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:41:09 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 22:49:54 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int  a = 17;
	int  b = 5;
	char c;

	ft_ultimate_div_mod(&a, &b);

	c = a + '0';
	write(1, &c, 1);
	write(1, " ", 1);
	c = b + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
*/