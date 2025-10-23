/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:40:35 by mgee              +#+    #+#             */
/*   Updated: 2025/10/23 21:06:03 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	printf("%d\n", ft_strcmp("Hello", "Hello"));  // same → 0
	printf("%d\n", ft_strcmp("Hello", "Hell"));   // first longer → positive
	printf("%d\n", ft_strcmp("Hell", "Hello"));   // first shorter → negative
	printf("%d\n", ft_strcmp("abc", "abd"));      // first smaller → negative
	printf("%d\n", ft_strcmp("abd", "abc"));      // first greater → positive
	return (0);
}
*/