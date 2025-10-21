/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:27:14 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 22:56:11 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int  d;
	int  m;
	char c;

	ft_div_mod(17, 5, &d, &m);

	c = d + '0';
	write(1, &c, 1);
	write(1, " ", 1);
	c = m + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
*/