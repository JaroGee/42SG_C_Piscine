/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:05:06 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 11:01:46 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
}

int	main(void)
{
	ft_is_negative(0);
	ft_is_negative(-1);
	ft_is_negative(20);
	return (0);
}

/*
#include <unistd.h>

void	ft_is_negative(int n);

static void	test(int n)
{
	if (n > 0)
		write(1, "n>0  Expect: P  Got: ", 22);
	else if (n < 0)
		write(1, "n<0  Expect: N  Got: ", 22);
	else
		write(1, "n=0  Expect: N  Got: ", 22);
	ft_is_negative(n);
	write(1, "\n", 1);
}

int	main(void)
{
	test(42);
	test(-7);
	test(0);
	return (0);
}
*/
