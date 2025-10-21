/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 05:22:10 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 08:17:11 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
	return (str);
}

/*
#include <unistd.h>
char	*ft_strlowcase(char *str);

static void	putstr(char *s)
{
	int i = 0; while (s[i]) { write(1, &s[i], 1); i++; } write(1, "\n", 1);
}

int	main(void)
{
	char a[] = "HeLLo 42!";
	putstr(ft_strlowcase(a)); // "hello 42!"
	return (0);
}
*/