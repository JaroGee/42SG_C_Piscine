/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:23:55 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 11:24:46 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	printf("%d\n", ft_strcmp("abc", "abc"));   // 0
	printf("%d\n", ft_strcmp("abc", "abd"));   // negative
	printf("%d\n", ft_strcmp("abd", "abc"));   // positive
	printf("%d\n", ft_strcmp("", ""));         // 0
	printf("%d\n", ft_strcmp("a", ""));        // positive
	printf("%d\n", ft_strcmp("", "a"));        // negative
	return (0);
}

