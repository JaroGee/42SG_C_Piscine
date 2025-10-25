/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:09:14 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 09:09:33 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void	putstr2(const char *s)
{
	while (*s)
		write(2, s++, 1);
}

static int	dump_fd(int fd)
{
	char	buf[4096];
	ssize_t	n;
	ssize_t	w;
	ssize_t	k;

	n = read(fd, buf, 4096);
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
		n = read(fd, buf, 4096);
	}
	return (n < 0);
}

int	validate_args(int argc)
{
	if (argc < 2)
	{
		putstr2("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		putstr2("Too many arguments.\n");
		return (1);
	}
	return (0);
}

int	display_file(const char *path)
{
	int	fd;
	int	err;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		putstr2("Cannot read file.\n");
		return (1);
	}
	err = dump_fd(fd);
	close(fd);
	if (err)
	{
		putstr2("Cannot read file.\n");
		return (1);
	}
	return (0);
}
