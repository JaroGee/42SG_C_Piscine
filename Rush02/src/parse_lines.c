/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:55 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 22:16:35 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	store_key_val(char *line, t_dict *out, int idx)
{
	char	*key;
	char	*val;

	key = trim_spaces(line);
	val = trim_spaces(line + ft_strlen(key) + 1);
	if (!*key || !*val)
		return (0);
	out->pairs[idx].key = ft_strdup(key);
	out->pairs[idx].val = ft_strdup(val);
	if (!out->pairs[idx].key || !out->pairs[idx].val)
		return (-1);
	return (1);
}

static int	handle_line(char *s, t_dict *out, int *pidx)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ':')
		i++;
	if (!s[i])
		return (0);
	s[i] = '\0';
	if (store_key_val(s, out, *pidx) < 0)
		return (-1);
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
	out->size = idx;
	return (0);
}
