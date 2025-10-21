/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 05:22:16 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 08:34:37 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	put_hex_byte(unsigned char b)
{
	char				out[2];
	char				*hex;

	hex = "0123456789abcdef";
	out[0] = hex[b / 16];
	out[1] = hex[b % 16];
	write(1, out, 2);
}

static void	put_hex_addr(unsigned long n)
{
	char				buf[16];
	char				*hex;
	int					i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buf[i] = hex[n % 16];
		n = n / 16;
		i--;
	}
	write(1, buf, 16);
}

static void	print_hex_area(unsigned char *p, unsigned int count)
{
	unsigned int		i;
	char				space;

	space = ' ';
	i = 0;
	write(1, ": ", 2);
	while (i < 16)
	{
		if (i < count)
			put_hex_byte(p[i]);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, &space, 1);
		i++;
	}
}

static void	print_ascii_area(unsigned char *p, unsigned int count)
{
	unsigned int		i;
	char				ch;

	i = 0;
	while (i < count)
	{
		ch = p[i];
		if (ch >= 32 && ch <= 126)
			write(1, &ch, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char		*p;
	unsigned int		i;
	unsigned int		remain;

	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		put_hex_addr((unsigned long)(p + i));
		if (size - i >= 16)
			remain = 16;
		else
			remain = size - i;
		print_hex_area(p + i, remain);
		print_ascii_area(p + i, remain);
		i = i + remain;
	}
	return (addr);
}

/*
#include <unistd.h>
void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char	data[] = "Bonjour les aminches\n\nc  est fou\ttout ce qu on "
		"peut faire avec...\n\n\nlol.lol ";
	ft_print_memory(data, sizeof(data) - 1);
	return (0);
}
*/