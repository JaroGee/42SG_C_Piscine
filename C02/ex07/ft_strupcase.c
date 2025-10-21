/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 05:22:08 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 08:16:17 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
	return (str);
}

/*
#include <unistd.h>
char	*ft_strupcase(char *str);

void	putstr(char *s)
{
	int i = 0; while (s[i]) { write(1, &s[i], 1); i++; } write(1, "\n", 1);
}

int	main(void)
{
	char a[] = "Hello 42!";
	char b[] = "";

	putstr(ft_strupcase(a)); 
	putstr(ft_strupcase(b));
	return (0);
}
*/
