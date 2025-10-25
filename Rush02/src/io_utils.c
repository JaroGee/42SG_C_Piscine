/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:34:56 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 14:34:56 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*slurp(const char *path)
{
	int		fd;
	int		r;
	char	*buf;
	char	tmp[4096];
	int		total;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = NULL;
	total = 0;
	while ((r = read(fd, tmp, 4096)) > 0)
	{
		char	*new = malloc(total + r + 1);
		if (!new)
			return (close(fd), free(buf), NULL);
		for (int i = 0; i < total; i++)
			new[i] = buf[i];
		for (int j = 0; j < r; j++)
			new[total + j] = tmp[j];
		new[total + r] = '\0';
		free(buf);
		buf = new;
		total += r;
	}
	close(fd);
	return (buf);
}
