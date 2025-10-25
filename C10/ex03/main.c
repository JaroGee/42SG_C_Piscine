/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:12:57 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 09:12:57 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

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
		if (dump_fd(0, &off))
			print_err(prog, "(stdin)");
		put_hex8(off);
		write(1, "\n", 1);
		return (0);
	}
	i = start;
	while (i < argc)
	{
		int fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			print_err(prog, argv[i]);
		else
		{
			if (dump_fd(fd, &off))
				print_err(prog, argv[i]);
			close(fd);
		}
		i++;
	}
	put_hex8(off);
	write(1, "\n", 1);
	return (0);
}
