/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 05:22:07 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 08:12:50 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

/*
#include <unistd.h>
int	ft_str_is_printable(char *str);

int	main(void)
{
	char	s[] = "Hello\tWorld";
	char	c;

	c = ft_str_is_printable("Hello!") + '0';
    write(1, &c, 1); write(1, "\n", 1);

	c = ft_str_is_printable(s) + '0';       
    write(1, &c, 1); write(1, "\n", 1);

	c = ft_str_is_printable("") + '0';      
    write(1, &c, 1); write(1, "\n", 1);
	return (0);
}
*/