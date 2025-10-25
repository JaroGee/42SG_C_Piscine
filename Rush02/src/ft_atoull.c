/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:58:22 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 01:51:36 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/*
** Simple ASCII -> unsigned long long.
** Assumes the string contains only digits (your validate_num guards that).
*/
unsigned long long	ft_atoull(const char *s)
{
	unsigned long long	n;
	int					i;

	n = 0ULL;
	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10ULL + (unsigned long long)(s[i] - '0');
		i++;
	}
	return (n);
}
