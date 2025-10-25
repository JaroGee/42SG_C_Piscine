/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:11:13 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 09:11:13 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

int	splice_fd(int fd)
{
	char	buf[28672];
	ssize_t	n;
	ssize_t	w;
	ssize_t	k;

	n = read(fd, buf, 28672);
	while (n > 0)
	{
		w = 0;
		while (w < n)
		{
			k = write(1, buf + w, (size_t)(n - w));
			if (k < 0)
				return (1);
			w += k;
		}
		n = read(fd, buf, 28672);
	}
	return (n < 0);
}

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
