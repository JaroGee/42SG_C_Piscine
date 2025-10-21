/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:28:00 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 22:50:16 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/*
#include <unistd.h>

int	ft_strlen(char *str);

int	main(void)
{
	int  n;
	char c;

	n = ft_strlen("Hello");
	c = n + '0';
	write(1, &c, 1);
	write(1, "\n", 1);

	n = ft_strlen("");
	c = n + '0';
	write(1, &c, 1);
	write(1, "\n", 1);

	n = ft_strlen("C01");
	c = n + '0';
	write(1, &c, 1);
	write(1, "\n", 1);

	return (0);
}
*/ 