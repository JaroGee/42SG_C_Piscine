/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:18:58 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 10:41:41 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)

{
	write(1, &c, 1);
}

int	main(void)

{
	ft_putchar('A');
	return (0);
}

/*
#include <unistd.h>

void	ft_putchar(char c);

int	main(void)
{
	write(1, "Expect: A\nGot:    ", 18);
	ft_putchar('A');
	write(1, "\n", 1);
	return (0);
}
*/