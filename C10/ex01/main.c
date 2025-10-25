/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 04:00:34 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 09:50:21 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

static void	handle_stdin(const char *prog)
{
	if (splice_fd(0))
		print_err(prog, "-");
}

static void	handle_file(const char *prog, const char *path)
{
	int	fd;
	int	err;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_err(prog, path);
		return ;
	}
	err = splice_fd(fd);
	if (err)
		print_err(prog, path);
	close(fd);
}

int	main(int argc, char **argv)
{
	char	*prog;
	int		i;

	prog = basename(argv[0]);
	if (argc == 1)
	{
		handle_stdin(prog);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			handle_stdin(prog);
		else
			handle_file(prog, argv[i]);
		i++;
	}
	return (0);
}
