/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:24:04 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 10:59:03 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)

{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}

int	main(void)

{
	ft_print_alphabet();
	return (0);
}

/*
#include <unistd.h>

void	ft_print_alphabet(void);

int	main(void)
{
	write(1, "Expect: abcdefghijklmnopqrstuvwxyz\nGot:    ", 43);
	ft_print_alphabet();
	write(1, "\n", 1);
	return (0);
}
*/
