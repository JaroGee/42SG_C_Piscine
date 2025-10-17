/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:41:55 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:26 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_div_mod(int a, int b, int *div, int *mod);
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
    int d, m;
    ft_div_mod(17, 5, &d, &m);
    putnbr(d); write(1, " ", 1); putnbr(m); write(1, "\n", 1);
    return (0);
}
