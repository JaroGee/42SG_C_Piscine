/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:17:07 by mgee              +#+    #+#             */
/*   Updated: 2025/10/23 01:17:51 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*
#include <stdio.h>

int	ft_recursive_power(int nb, int power);

int	main(void)
{
	printf("2^10 = %d\n", ft_recursive_power(2, 10));
	printf("7^0  = %d\n", ft_recursive_power(7, 0));
	printf("4^-1 = %d\n", ft_recursive_power(4, -1));
}
*/