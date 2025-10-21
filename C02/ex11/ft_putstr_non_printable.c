/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 06:16:22 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 08:23:29 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	_put_hex(unsigned char c)
{
	char	*hex;
	char	out[2];

	hex = "0123456789abcdef";
	out[0] = hex[c / 16];
	out[1] = hex[c % 16];
	write(1, out, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (c < 32 || c > 126)
		{
			write(1, "\\", 1);
			_put_hex(c);
		}
		else
			write(1, &c, 1);
		i++;
	}
}

/*
#include <unistd.h>
void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char s[] = "Coucou\ntu vas bien?\tOK\1\2";
	ft_putstr_non_printable(s);
	write(1, "\n", 1);
	return (0);
}
*/