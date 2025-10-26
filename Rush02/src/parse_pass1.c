/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pass1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:43 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 02:24:55 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/*
** Count only lines that look like "something:something"
** - Handles files without trailing '\n'
** - Skips blank lines and lines without a colon
*/
int	pass1_count_pairs(char *buf)
{
	int	i;
	int	start;
	int	has_colon;
	int	count;

	i = 0;
	start = 0;
	has_colon = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == ':')
			has_colon = 1;
		if (buf[i] == '\n')
		{
			if (i > start && has_colon)
				count++;
			start = i + 1;
			has_colon = 0;
		}
		i++;
	}
	if (i > start && has_colon)
		count++;
	return (count);
}
