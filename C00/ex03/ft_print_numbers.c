/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:52:17 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 10:49:25 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	n;

	n = '0';
	while (n <= '9')
	{
		write(1, &n, 1);
		n++;
	}
}

void	ft_print_numbers(void);

int	main(void)
{
	ft_print_numbers();
	write(1, "\n", 1);
	return (0);
}

/*
#include <unistd.h>

void	ft_print_numbers(void);

int	main(void)
{
	write(1, "Expect: 0123456789\nGot:    ", 27);
	ft_print_numbers();
	write(1, "\n", 1);
	return (0);
}
*/