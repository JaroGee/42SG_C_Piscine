/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:07:04 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 17:07:04 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char s[] = "the 42 piscine teaches strings";
	printf("%s\n", ft_strstr(s, "42"));        // "42 piscine teaches strings"
	printf("%s\n", ft_strstr(s, "piscine"));   // "piscine teaches strings"
	printf("%s\n", ft_strstr(s, ""));          // whole string (empty needle)
	printf("%p\n", (void *)ft_strstr(s, "xyz")); // (nil) on many libc prints
	return (0);
}

