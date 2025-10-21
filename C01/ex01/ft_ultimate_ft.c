/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:41:56 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 22:45:00 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

/*
#include <unistd.h>

void	ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int n;
	int *p1 = &n; int **p2 = &p1; int ***p3 = &p2;
	int ****p4 = &p3; int *****p5 = &p4; int ******p6 = &p5;
	int *******p7 = &p6; int ********p8 = &p7; int *********p9 = &p8;
	char c;

	ft_ultimate_ft(p9);
	c = (n / 10) + '0';
	write(1, &c, 1);
	c = (n % 10) + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
*/