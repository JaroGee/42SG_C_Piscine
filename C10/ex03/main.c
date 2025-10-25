/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:12:57 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 09:40:07 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

static void	process_file(const char *prog, const char *path, unsigned long *off)
{
	int	fd;
	int	err;

	fd = -1;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_err(prog, path);
		return ;
	}
	err = dump_fd(fd, off);
	close(fd);
	if (err)
		print_err(prog, path);
}

static void	print_total(unsigned long off)
{
	put_hex8(off);
	write(1, "\n", 1);
}

static void	process_stdin(const char *prog, unsigned long *off)
{
	if (dump_fd(0, off))
		print_err(prog, "(stdin)");
	print_total(*off);
}

int	main(int argc, char **argv)
{
	char			*prog;
	int				i;
	int				start;
	unsigned long	off;

	prog = basename(argv[0]);
	off = 0;
	start = 1;
	if (argc > 1 && strcmp(argv[1], "-C") == 0)
		start = 2;
	if (start >= argc)
	{
		process_stdin(prog, &off);
		return (0);
	}
	i = start;
	while (i < argc)
	{
		process_file(prog, argv[i], &off);
		i++;
	}
	print_total(off);
	return (0);
}
