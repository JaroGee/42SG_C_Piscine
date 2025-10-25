/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 07:26:17 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 09:07:13 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

/* handle one file/stdin; return 1 on error, 0 on success */
static int	handle_one(const char *prog, const char *name, long count)
{
	int	fd;
	int	err;

	fd = -1;
	err = 0;
	if (name[0] == '-' && name[1] == '\0')
		err = run_tail_on_fd(0, count);
	else
	{
		fd = open(name, O_RDONLY);
		if (fd < 0)
		{
			print_err(prog, name);
			return (1);
		}
		err = run_tail_on_fd(fd, count);
		close(fd);
	}
	if (err)
	{
		print_err(prog, name);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*prog;
	long	count;
	int		i;

	prog = basename(argv[0]);
	if (argc < 3 || strcmp(argv[1], "-c") != 0 || !parse_count(argv[2], &count))
	{
		write(2, "usage: ", 7);
		write(2, prog, (int)strlen(prog));
		write(2, " -c N file...\n", 14);
		return (1);
	}
	if (argc == 3)
	{
		if (run_tail_on_fd(0, count))
			return (1);
		return (0);
	}
	i = 3;
	while (i < argc)
	{
		handle_one(prog, argv[i], count);
		i++;
	}
	return (0);
}
