/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:30:37 by mgee              +#+    #+#             */
/*   Updated: 2025/10/18 11:30:37 by mgee             ###   ########.fr       */
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

/* Expect exactly 16 tokens, each '1'..'4' */
int	parse_clues_4x4(const char *s, int out16[16])
{
	int i;

	i = 0;
	while (*s && i < 16)
	{
		while (is_space(*s))
			s++;
		if (!*s)
			break;
		if (!is_digit(*s))
			return (0);
		if (*s < '1' || *s > '4')
			return (0);
		out16[i++] = *s - '0';
		s++;
		while (is_space(*s))
			s++;
	}
	if (i != 16)
		return (0);
	/* no trailing non-space garbage allowed */
	while (is_space(*s))
		s++;
	return (*s == '\0');
}

/*Purpose
Reads the argument string (the 16 clues),
validates it, and converts to integers.
What it does
Skips spaces and tabs.
Accepts only digits '1'–'4'.
Fills out16[16] array in this order:
top[4], bottom[4], left[4], right[4]
Returns 1 on success, 0 on failure.
Edge cases
Too few or too many clues → failure.
Non-digit or out-of-range digit → failure.
Trailing garbage after clues → failure.
Usage
Called from main() to parse command-line input.
*/