/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:58:56 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 08:59:44 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

static long	fill_buf(int fd, char *ring, long count, long *pos)
{
	long	i;
	char	c;

	i = 0;
	*pos = 0;
	while (read(fd, &c, 1) > 0)
	{
		ring[*pos] = c;
		(*pos)++;
		if (*pos == count)
			*pos = 0;
		i++;
	}
	return (i);
}

int	run_tail_on_fd(int fd, long count)
{
	char	*ring;
	long	pos;
	long	tot;
	long	len;

	if (count <= 0)
		return (0);
	ring = (char *)malloc((size_t)count);
	if (!ring)
		return (1);
	tot = fill_buf(fd, ring, count, &pos);
	if (tot >= count)
	{
		len = count - pos;
		if (len > 0)
			write(1, ring + pos, (size_t)len);
		if (pos > 0)
			write(1, ring, (size_t)pos);
	}
	else if (tot > 0)
		write(1, ring, (size_t)tot);
	free(ring);
	return (0);
}
