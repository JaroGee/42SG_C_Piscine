/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:11:43 by mgee              +#+    #+#             */
/*   Updated: 2025/10/23 01:55:16 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*
#include <stdio.h>

int	ft_recursive_factorial(int nb);

int	main(void)
{
	printf("5! = %d\n", ft_recursive_factorial(5));
	printf("0! = %d\n", ft_recursive_factorial(0));
	printf("-3! = %d\n", ft_recursive_factorial(-3)); 
}
*/