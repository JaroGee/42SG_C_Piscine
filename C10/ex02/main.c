/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:11:24 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 06:16:38 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

#define RBUFSZ 4096

static void	ft_puts2(const char *s)
{
	while (*s)
		write(2, s++, 1);
}

static void	ft_printerr(const char *prog, const char *path)
{
	const char	*msg;

	msg = strerror(errno);
	ft_puts2(prog);
	ft_puts2(": ");
	ft_puts2(path);
	ft_puts2(": ");
	ft_puts2(msg);
	ft_puts2("\n");
}

static int	parse_count(const char *s, long *out)
{
	long	v;
	int		i;

	v = 0;
	i = 0;

	if (!s || !s[0])
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		v = v * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0')
		return (0);
	*out = v;
	return (1);
}

static int	tail_fd_last_c(int fd, long count)
{
	char	*ring;
	char	rbuf[RBUFSZ];
	ssize_t	n;
	long	filled;
	long	pos;
	ssize_t	i;

	if (count <= 0)
		return (0);
	ring = (char *)malloc((size_t)count);
	if (!ring)
		return (1);
	filled = 0;
	pos = 0;
	n = read(fd, rbuf, RBUFSZ);
	while (n > 0)
	{
		i = 0;
		while (i < n)
		{
			ring[pos] = rbuf[i];
			pos = (pos + 1) % count;
			if (filled < count)
				filled++;
			i++;
		}
		n = read(fd, rbuf, RBUFSZ);
	}
	if (n < 0)
	{
		free(ring);
		return (1);
	}
	if (filled > 0)
	{
		long	start;
		long	j;
		long	idx;

		start = (filled == count) ? pos : 0;
		j = 0;
		while (j < filled)
		{
			idx = (start + j) % count;
			if (write(1, &ring[idx], 1) < 0)
			{
				free(ring);
				return (1);
			}
			j++;
		}
	}
	free(ring);
	return (0);
}

static void	print_header(const char *name, int *need_nl)
{
	if (*need_nl)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	write(1, name, (int)strlen(name));
	write(1, " <==\n", 5);
	*need_nl = 1;
}

static void	process_one(const char *prog, const char *name, long count)
{
	int	fd;
	int	err;

	fd = -1;
	err = 0;

	if (name[0] == '-' && name[1] == '\0')
		err = tail_fd_last_c(0, count);
	else
	{
		fd = open(name, O_RDONLY);
		if (fd < 0)
		{
			ft_printerr(prog, name);
			return ;
		}
		err = tail_fd_last_c(fd, count);
		close(fd);
	}
	if (err)
		ft_printerr(prog, name);
}

int	main(int argc, char **argv)
{
	char	*prog;
	long	count;
	int		i;
	int		many;
	int		need_nl;

	prog = basename(argv[0]);

	if (argc < 3 || strcmp(argv[1], "-c") != 0 || !parse_count(argv[2], &count))
	{
		ft_puts2("usage: ");
		ft_puts2(prog);
		ft_puts2(" -c N file...\n");
		return (1);
	}
	if (argc == 3)
		return (tail_fd_last_c(0, count) ? 1 : 0);
	many = (argc - 3 > 1);
	need_nl = 0;
	i = 3;
	while (i < argc)
	{
		if (many)
			print_header(argv[i], &need_nl);
		process_one(prog, argv[i], count);
		i++;
	}
	return (0);
}
