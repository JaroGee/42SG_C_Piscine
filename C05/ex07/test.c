/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:07:38 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 20:07:43 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_find_next_prime(int nb);

int	main(void)
{
	printf("next_prime(14) = %d\n", ft_find_next_prime(14));
	printf("next_prime(17) = %d\n", ft_find_next_prime(17));
	printf("next_prime(-8) = %d\n", ft_find_next_prime(-8));
}