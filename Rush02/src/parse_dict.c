/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:38:59 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 03:27:27 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	init_out(t_dict *out)
{
	out->pairs = 0;
	out->size = 0;
}

static int	alloc_pairs(t_dict *out, int cap)
{
	int	i;

	out->pairs = (t_pair *)malloc(sizeof(t_pair) * cap);
	if (!out->pairs)
		return (1);
	i = 0;
	while (i < cap)
	{
		out->pairs[i].key = 0;
		out->pairs[i].val = 0;
		i++;
	}
	out->size = 0;
	return (0);
}

static int	fill_and_sort(char *buf, t_dict *out)
{
	int	n;

	n = parse_lines_into_pairs(buf, out);
	if (n <= 0)
		return (1);
	out->size = n;
	sort_pairs(out);
	return (0);
}

int	parse_dict(const char *path, t_dict *out)
{
	char	*buf;
	int		cap;
	int		rc;

	init_out(out);
	buf = slurp(path);
	if (!buf)
		return (1);
	cap = pass1_count_pairs(buf);
	if (cap <= 0 || alloc_pairs(out, cap) != 0)
	{
		free(buf);
		return (1);
	}
	rc = fill_and_sort(buf, out);
	free(buf);
	if (rc != 0)
		free_dict(out);
	return (rc);
}
