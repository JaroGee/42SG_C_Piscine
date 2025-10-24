/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:19:32 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 01:46:08 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

/*
#include <stdio.h>
int	ft_is_prime(int nb);

int	main(void)
{
	int	tests[] = {-5, 0, 1, 2, 3, 4, 5, 25, 29, 97, 99};
	int	n = sizeof(tests)/sizeof(tests[0]);
	for (int i = 0; i < n; i++)
		printf("%d -> %d\n", tests[i], ft_is_prime(tests[i]));
}
*/