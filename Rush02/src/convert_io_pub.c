/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_io_pub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:46:52 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 01:46:57 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	write_space_if_needed(int *need_space)
{
	if (*need_space)
	{
		if (write(1, " ", 1) < 0)
			return (-1);
	}
	else
		*need_space = 1;
	return (0);
}

int	write_word(const char *s)
{
	int	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (len < 0)
		return (-1);
	if (write(1, s, (size_t)len) < 0)
		return (-1);
	return (0);
}
