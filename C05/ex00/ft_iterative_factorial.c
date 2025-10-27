/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:09:38 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 20:55:04 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	while (nb > 1)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}

/*
#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	main(void)
{
	printf("0! = %d\n", ft_iterative_factorial(0));
	printf("1! = %d\n", ft_iterative_factorial(1));
	printf("5! = %d\n", ft_iterative_factorial(5));
	printf("-3! = %d\n", ft_iterative_factorial(-3));
}
*/