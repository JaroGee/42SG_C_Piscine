/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:42:42 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 22:48:44 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
#include <unistd.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int  a = 1;
	int  b = 2;
	char c;

	ft_swap(&a, &b);

	c = a + '0';
	write(1, &c, 1);
	write(1, " ", 1);
	c = b + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
*/