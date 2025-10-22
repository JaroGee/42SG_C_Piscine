/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:38:33 by mgee              +#+    #+#             */
/*   Updated: 2025/10/22 18:38:33 by mgee             ###   ########.fr       */
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
#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	char text[] = "Hello 42!";
	printf("Length: %d\n", ft_strlen(text));
	return (0);
}
*/