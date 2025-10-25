/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_scaled_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:47:55 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 01:58:04 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static unsigned long long	pow1000(int e)
{
	unsigned long long	x;
	int					i;

	x = 1ULL;
	i = 0;
	while (i < e)
	{
		x *= 1000ULL;
		i++;
	}
	return (x);
}

void	print_scaled(const t_dict *d, unsigned long long n)
{
	int					group;
	int					need_space;
	unsigned long long	div;
	int					chunk;

	if (n == 0ULL)
	{
		write_word(dict_find(d, "0"));
		return ;
	}
	need_space = 0;
	group = 0;
	while (pow1000(group + 1) <= n)
		group++;
	while (group >= 0)
	{
		div = pow1000(group);
		chunk = (int)((n / div) % 1000ULL);
		if (chunk)
			spell_chunk_with_scale(d, chunk, scale_for_group(group), &need_space);
		group--;
	}
}
