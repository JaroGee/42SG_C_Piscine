/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 04:41:45 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 05:32:56 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <unistd.h>

int	ft_str_is_alpha(char *str);

static void	putchair_fd(char c)
{
	write(1, &c, 1);
}

static void	putnbr_fd(int n)
{
	if (n > 9)
		putnbr_fd(n / 10);
	putchar_fd((n % 10) + '0');
}

int	main(void)
{
	int	res;

	res = ft_str_is_alpha("HelloWorld");
	putnbr_fd(res); putchar_fd('\n'); // expect 1

	res = ft_str_is_alpha("Hello42");
	putnbr_fd(res); putchar_fd('\n'); // expect 0

	res = ft_str_is_alpha("");
	putnbr_fd(res); putchar_fd('\n'); // expect 1 (empty string)
	return (0);
}
*/