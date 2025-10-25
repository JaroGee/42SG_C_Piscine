/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:38:42 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 22:02:20 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	is_space_char(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	return (0);
}

static int	right_trim_idx(char *s, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0 && is_space_char(s[i]))
	{
		s[i] = '\0';
		i--;
	}
	return (i);
}

char	*trim_spaces(char *s)
{
	int	i;
	int	len;

	if (!s)
		return (s);
	i = 0;
	while (s[i] && is_space_char(s[i]))
		i++;
	len = 0;
	while (s[i + len])
		len++;
	(void)right_trim_idx(s + i, len);
	return (s + i);
}
