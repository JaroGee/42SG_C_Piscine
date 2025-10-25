/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:58:45 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 08:58:45 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	parse_count(const char *s, long *out)
{
	long	v;
	int		i;

	v = 0;
	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		v = v * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0')
		return (0);
	*out = v;
	return (1);
}

void	print_err(const char *prog, const char *name)
{
	write(2, prog, (int)strlen(prog));
	write(2, ": ", 2);
	write(2, name, (int)strlen(name));
	write(2, ": ", 2);
	write(2, strerror(errno), (int)strlen(strerror(errno)));
	write(2, "\n", 1);
}
