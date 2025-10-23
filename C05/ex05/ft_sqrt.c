/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:18:38 by mgee              +#+    #+#             */
/*   Updated: 2025/10/23 21:00:43 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x;

	if (nb <= 0)
		return (0);
	x = 1;
	while (x <= 46340 && x * x <= nb)
	{
		if (x * x == nb)
			return (x);
		x++;
	}
	return (0);
}

/*
#include <stdio.h>
int	ft_sqrt(int nb);

int	main(void)
{
	printf("sqrt(16) = %d\n", ft_sqrt(16));
	printf("sqrt(15) = %d\n", ft_sqrt(15));
	printf("sqrt(1)  = %d\n", ft_sqrt(1));
	printf("sqrt(0)  = %d\n", ft_sqrt(0));
}
*/