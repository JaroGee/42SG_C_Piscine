/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_io_pub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:46:52 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 03:43:34 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	write_space_if_needed(int *need_space)
{
	if (*need_space)
	{
		write(1, " ", 1);
	}
	*need_space = 1;
	return (0);
}

int	write_word(const char *s)
{
	int	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (len > 0)
		write(1, s, len);
	return (0);
}
