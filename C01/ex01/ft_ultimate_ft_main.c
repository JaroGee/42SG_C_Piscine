/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:36:56 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 14:31:17 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_ultimate_ft(int *********nbr);

void    putnbr(int n)
{
    char c;
    if (n >= 10) putnbr(n / 10);
    c = '0' + (n % 10);
    write(1, &c, 1);
}

int     main(void)
{
    int x = 0;
    int *p1 = &x; int **p2 = &p1; int ***p3 = &p2; int ****p4 = &p3;
    int *****p5 = &p4; int ******p6 = &p5; int *******p7 = &p6;
    int ********p8 = &p7; int *********p9 = &p8;
    ft_ultimate_ft(p9);
    putnbr(x);
    write(1, "\n", 1);
    return (0);
}
