/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexfmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:12:21 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 09:50:18 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	put_hex8(unsigned long v)
{
	char	hex[8];
	int		i;

	i = 7;
	while (i >= 0)
	{
		hex[i] = "0123456789abcdef"[v & 0xF];
		v >>= 4;
		i--;
	}
	write(1, hex, 8);
}

void	put_hex2(unsigned char b)
{
	char	out[2];

	out[0] = "0123456789abcdef"[(b >> 4) & 0xF];
	out[1] = "0123456789abcdef"[b & 0xF];
	write(1, out, 2);
}

static void	print_hex_cols(const unsigned char *buf, int len)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < len)
			put_hex2(buf[i]);
		else
			write(1, "  ", 2);
		write(1, " ", 1);
		if (i == 7)
			write(1, " ", 1);
		i++;
	}
}

static void	print_ascii(const unsigned char *buf, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (buf[i] >= 32 && buf[i] <= 126)
			write(1, (char *)&buf[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_line(unsigned long base, unsigned char *buf, int len)
{
	put_hex8(base);
	write(1, "  ", 2);
	print_hex_cols(buf, len);
	write(1, " |", 2);
	print_ascii(buf, len);
	write(1, "|\n", 2);
}
