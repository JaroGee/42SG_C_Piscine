/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:19:51 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 01:46:08 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (!ft_is_prime(nb))
		nb += 2;
	return (nb);
}

/*
#include <stdio.h>
int	ft_find_next_prime(int nb);

int	main(void)
{
	printf("next_prime(14) = %d\n", ft_find_next_prime(14));
	printf("next_prime(17) = %d\n", ft_find_next_prime(17));
	printf("next_prime(-8) = %d\n", ft_find_next_prime(-8));
*/