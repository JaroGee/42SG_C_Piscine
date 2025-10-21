/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:18:30 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 10:42:47 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		write(1, &c, 1);
		c--;
	}
}

int	main(void)

{
	ft_print_reverse_alphabet();
	return (0);
}

/*
#include <unistd.h>

void	ft_print_reverse_alphabet(void);

int	main(void)
{
	write(1, "Expect: zyxwvutsrqponmlkjihgfedcba\nGot:    ", 43);
	ft_print_reverse_alphabet();
	write(1, "\n", 1);
	return (0);
}
*/