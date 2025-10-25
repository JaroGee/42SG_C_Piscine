/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:12:40 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 09:12:46 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	print_err(const char *prog, const char *path)
{
	const char	*msg;

	msg = strerror(errno);
	write(2, prog, (int)strlen(prog));
	write(2, ": ", 2);
	write(2, path, (int)strlen(path));
	write(2, ": ", 2);
	write(2, msg, (int)strlen(msg));
	write(2, "\n", 1);
}

int	dump_fd(int fd, unsigned long *off)
{
	unsigned char	buf[16];
	ssize_t			n;

	n = read(fd, buf, 16);
	while (n > 0)
	{
		print_line(*off, buf, (int)n);
		*off += (unsigned long)n;
		n = read(fd, buf, 16);
	}
	return (n < 0);
}
