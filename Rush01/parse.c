/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:04:08 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 09:17:10 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static const char	*skip_spaces(const char *s)
{
	while (*s && is_space(*s))
		s++;
	return (s);
}

/* read exactly one token '1'..'4'; return -1 on error */
static int	read_token_4x4(const char **ps)
{
	const char	*s;

	s = skip_spaces(*ps);
	if (!*s || !is_digit(*s) || *s < '1' || *s > '4')
		return (-1);
	*ps = s + 1;
	return ((int)(*s - '0'));
}

int	parse_clues_4x4(const char *s, int out16[16])
{
	int	i;
	int	val;

	i = 0;
	while (i < 16)
	{
		val = read_token_4x4(&s);
		if (val == -1)
			return (0);
		out16[i] = val;
		i++;
		s = skip_spaces(s);
	}
	s = skip_spaces(s);
	return (*s == '\0');
}
