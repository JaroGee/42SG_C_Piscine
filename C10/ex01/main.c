/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 04:00:34 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 06:16:38 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

#define BUFSZ 28672

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

static int	splice_fd(int fd)
{
	char	buf[BUFSZ];
	ssize_t	n;
	ssize_t	w;
	ssize_t	k;

	n = read(fd, buf, BUFSZ);
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
		n = read(fd, buf, BUFSZ);
	}
	return (n < 0);
}

static void	process_arg(const char *prog, const char *arg)
{
	int	fd;
	int	err;

	fd = -1;
	err = 0;
	if (arg[0] == '-' && arg[1] == '\0')
	{
		err = splice_fd(0);
		if (err)
			ft_printerr(prog, "-");
		return ;
	}
	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		ft_printerr(prog, arg);
		return ;
	}
	err = splice_fd(fd);
	if (err)
		ft_printerr(prog, arg);
	close(fd);
}

int	main(int argc, char **argv)
{
	char	*prog;
	int		i;

	prog = basename(argv[0]);
	if (argc == 1)
		return (splice_fd(0));
	i = 1;
	while (i < argc)
	{
		process_arg(prog, argv[i]);
		i++;
	}
	return (0);
}
