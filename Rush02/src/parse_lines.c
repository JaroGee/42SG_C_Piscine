/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:55 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 04:01:52 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	add_pair(const char *k, const char *v, t_dict *out, int idx)
{
	if (!*k || !*v)
		return (0);
	out->pairs[idx].key = ft_strdup(k);
	out->pairs[idx].val = ft_strdup(v);
	if (!out->pairs[idx].key || !out->pairs[idx].val)
		return (-1);
	return (1);
}

static int	handle_line(char *s, t_dict *out, int *pidx)
{
	int		i;
	char	*key;
	char	*val;
	int		st;

	i = 0;
	while (s[i] && s[i] != ':')
		i++;
	if (!s[i])
		return (0);
	s[i] = '\0';
	key = trim_spaces(s);
	val = trim_spaces(s + i + 1);
	st = add_pair(key, val, out, *pidx);
	if (st < 0)
		return (-1);
	if (st > 0)
		(*pidx)++;
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
			if (handle_line(buf + start, out, &idx) < 0)
				return (-1);
			start = i + 1;
		}
		i++;
	}
	if (start < i && handle_line(buf + start, out, &idx) < 0)
		return (-1);
	return (idx);
}
