/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:35:01 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 06:16:38 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUF_SZ 4096

static void	ft_putstr_fd(int fd, const char *s)
{
	while (*s)
		write(fd, s++, 1);
}

static int	ft_dump_fd(int fd)
{
	char	buf[BUF_SZ];
	ssize_t	n;
	ssize_t	w;
	ssize_t	k;

	n = read(fd, buf, BUF_SZ);
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
		n = read(fd, buf, BUF_SZ);
	}
	return (n < 0);
}

static int	validate_args(int argc)
{
	if (argc < 2)
	{
		ft_putstr_fd(2, "File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_fd(2, "Too many arguments.\n");
		return (1);
	}
	return (0);
}

static int	open_and_dump(const char *path)
{
	int	fd;
	int	err;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(2, "Cannot read file.\n");
		return (1);
	}
	err = ft_dump_fd(fd);
	close(fd);
	if (err)
	{
		ft_putstr_fd(2, "Cannot read file.\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	ret;

	if (validate_args(argc))
		return (1);
	ret = open_and_dump(argv[1]);
	return (ret);
}
