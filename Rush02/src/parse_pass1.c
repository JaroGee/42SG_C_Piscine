/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pass1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:43 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 22:01:32 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	has_colon(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ':')
			return (1);
		i++;
	}
	return (0);
}

int	pass1_count_pairs(char *buf)
{
	int	i;
	int	count;
	int	start;

	i = 0;
	count = 0;
	while (buf[i])
	{
		start = i;
		while (buf[i] && buf[i] != '\n')
			i++;
		if (has_colon(&buf[start]))
			count++;
		if (buf[i] == '\n')
			i++;
	}
	return (count);
}
