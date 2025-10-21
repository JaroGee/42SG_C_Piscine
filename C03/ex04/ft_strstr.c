/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:47:47 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 08:53:36 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0'
			&& str[i + j] != '\0'
			&& str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	text[] = "Find the needle in the haystack.";
	char	*res;

	res = ft_strstr(text, "needle");
	printf("Found : %s\n", res);
    // starts at "needle in..."
	res = ft_strstr(text, "cat");
	printf("Missing: %p\n", (void *)res);
    // (nil)
	res = ft_strstr(text, "");
	printf("Empty : %s\n", res);
    // whole string
	return (0);
}
*/