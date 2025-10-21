/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod_main.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:42:31 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 13:46:58 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_ultimate_div_mod(int *a, int *b);
void    putnbr(int n);

void    putnbr(int n)
{
    char c;
    if (n < 0){ write(1, "-", 1); n = -n; }
    if (n >= 10) putnbr(n / 10);
    c = '0' + (n % 10);
    write(1, &c, 1);
}

int     main(void)
{
    int x = 17, y = 5;
    ft_ultimate_div_mod(&x, &y);
    putnbr(x); write(1, " ", 1); putnbr(y); write(1, "\n", 1);
    return (0);
}
