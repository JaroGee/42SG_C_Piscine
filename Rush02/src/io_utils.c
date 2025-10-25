/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:34:56 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 22:09:23 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*grow(char *old, int oldsz, int newsz)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(newsz);
	if (!tmp)
		return (0);
	i = 0;
	while (i < oldsz)
	{
		tmp[i] = old[i];
		i++;
	}
	if (old)
		free(old);
	return (tmp);
}

static int	read_into_buf(int fd, char **buf, int *cap, int *len)
{
	char	tmp[1024];
	int		r;
	int		i;

	r = read(fd, tmp, 1024);
	while (r > 0)
	{
		if (*len + r + 1 > *cap)
		{
			*cap = *len + r + 1 + 1024;
			*buf = grow(*buf, *len, *cap);
			if (!*buf)
				return (1);
		}
		i = 0;
		while (i < r)
		{
			(*buf)[*len + i] = tmp[i];
			i++;
		}
		*len += r;
		r = read(fd, tmp, 1024);
	}
	return (0);
}

char	*slurp(const char *path)
{
	int		fd;
	char	*buf;
	int		cap;
	int		len;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = 0;
	cap = 0;
	len = 0;
	if (read_into_buf(fd, &buf, &cap, &len) != 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (!buf && len == 0)
		return (0);
	if (buf)
		buf[len] = '\0';
	return (buf);
}
