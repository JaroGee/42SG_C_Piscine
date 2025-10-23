/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 05:22:11 by mgee              +#+    #+#             */
/*   Updated: 2025/10/23 17:24:41 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_is_alnum(char c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

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

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (_is_alnum(str[i]))
		{
			if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - ('a' - 'A');
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}

/*
#include <unistd.h>
char	*ft_strcapitalize(char *str);

static void	putstr(char *s)
{
	int i = 0; while (s[i]) { write(1, &s[i], 1); i++; } write(1, "\n", 1);
}

int	main(void)
{
	char a[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	putstr(ft_strcapitalize(a));
	// Expect: "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un"
	return (0);
}
*/