/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:38:59 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 22:09:12 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	init_out(t_dict *out)
{
	out->pairs = 0;
	out->size = 0;
	return (0);
}

static int	alloc_pairs_from_buf(char *buf, t_dict *out)
{
	int	count;

	count = pass1_count_pairs(buf);
	if (count <= 0)
		return (1);
	out->pairs = (t_pair *)malloc(sizeof(t_pair) * count);
	if (!out->pairs)
		return (1);
	out->size = count;
	return (0);
}

static int	fill_and_sort(char *buf, t_dict *out)
{
	int	rc;

	rc = parse_lines_into_pairs(buf, out);
	if (rc != 0)
	{
		free_dict(out);
		return (1);
	}
	sort_pairs(out);
	return (0);
}

int	parse_dict(const char *path, t_dict *out)
{
	char	*buf;
	int		rc;

	init_out(out);
	buf = slurp(path);
	if (!buf)
		return (1);
	if (alloc_pairs_from_buf(buf, out) != 0)
	{
		free(buf);
		return (1);
	}
	rc = fill_and_sort(buf, out);
	free(buf);
	return (rc);
}
