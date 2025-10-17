/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:24:23 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:39:35 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    *ft_print_memory(void *addr, unsigned int size);

int     main(void)
{
    char data[] = "Hello\t42 Piscine!\n\x01\x02\x7Fend";
    ft_print_memory(data, sizeof(data) - 1);
    return (0);
}
