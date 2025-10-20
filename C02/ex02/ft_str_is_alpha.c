/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 04:41:45 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 05:50:39 by mgee             ###   ########.fr       */
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

int	main(void)
{
	char	str1[] = "HelloWorld";
	char	str2[] = "Hello42";
	char	str3[] = "";
	char	result;

	result = ft_str_is_alpha(str1) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	result = ft_str_is_alpha(str2) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	result = ft_str_is_alpha(str3) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	return (0);
}
*/