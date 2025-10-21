/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:48:05 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 13:50:53 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_rev_int_tab(int *tab, int size);

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
    int a[5] = {1, 2, 3, 4, 5};
    ft_rev_int_tab(a, 5);
    for (int i = 0; i < 5; i++)
    {
        putnbr(a[i]); write(1, i == 4 ? "\n" : " ", 1);
    }
    return (0);
}
