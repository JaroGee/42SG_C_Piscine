/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:15:50 by mgee              +#+    #+#             */
/*   Updated: 2025/10/23 21:06:03 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	result = 1;
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

/*
#include <stdio.h>

int	ft_iterative_power(int nb, int power);

int	main(void)
{
	printf("2^5 = %d\n", ft_iterative_power(2, 5));
	printf("0^0 = %d\n", ft_iterative_power(0, 0));
	printf("3^-2 = %d\n", ft_iterative_power(3, -2));
*/