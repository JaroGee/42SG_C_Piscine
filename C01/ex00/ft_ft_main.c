/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:33:23 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:26 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_ft(int *nbr);

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
    ft_ft(&x);
    putnbr(x);
    write(1, "\n", 1);
    return (0);
}
