/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:55 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 02:16:08 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	split_colon(char *line, char **key, char **val)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (!line[i])
		return (0);
	line[i] = '\0';
	*key = trim_spaces(line);
	*val = trim_spaces(line + i + 1);
	if (!**key || !**val)
		return (0);
	return (1);
}

static int	store_line(char *line, t_dict *out, int *pidx)
{
	char	*key;
	char	*val;
	int		rc;

	rc = split_colon(line, &key, &val);
	if (rc < 0)
		return (-1);
	if (rc == 0)
		return (0);
	out->pairs[*pidx].key = ft_strdup(key);
	out->pairs[*pidx].val = ft_strdup(val);
	if (!out->pairs[*pidx].key || !out->pairs[*pidx].val)
		return (-1);
	(*pidx)++;
	return (1);
}

static int	flush_segment(char *seg, t_dict *out, int *pidx)
{
	int	rc;

	rc = store_line(seg, out, pidx);
	if (rc < 0)
		return (-1);
	return (0);
}

int	parse_lines_into_pairs(char *buf, t_dict *out)
{
	int	i;
	int	start;
	int	idx;

	i = 0;
	start = 0;
	idx = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			if (flush_segment(buf + start, out, &idx) < 0)
				return (-1);
			start = i + 1;
		}
		i++;
	}
	if (start < i && flush_segment(buf + start, out, &idx) < 0)
		return (-1);
	out->size = idx;
	return (0);
}
