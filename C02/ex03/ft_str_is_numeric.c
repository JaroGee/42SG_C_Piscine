/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 05:22:01 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 06:17:24 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*#include <unistd.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char	str1[] = "123456";
	char	str2[] = "42Hello";
	char	str3[] = "";
	char	c;

	c = ft_str_is_numeric(str1) + '0';
	write(1, &c, 1);
	write(1, "\n", 1);

	c = ft_str_is_numeric(str2) + '0';
	write(1, &c, 1);
	write(1, "\n", 1);

	c = ft_str_is_numeric(str3) + '0';
	write(1, &c, 1);
	write(1, "\n", 1);

	return (0);
}
*/