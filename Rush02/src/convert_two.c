/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:18 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 22:04:01 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	int_to_key(int v, char *k)
{
	if (v < 10)
	{
		k[0] = (char)('0' + v);
		k[1] = '\0';
	}
	else
	{
		k[0] = (char)('0' + (v / 10));
		k[1] = (char)('0' + (v % 10));
		k[2] = '\0';
	}
}

static int	write_num_word(const t_dict *d, int v, int *need_space)
{
	const char	*word;
	char		key[3];

	int_to_key(v, key);
	word = dict_find(d, key);
	if (!word)
		return (1);
	if (write_space_if_needed(need_space) != 0)
		return (1);
	if (write_word(word) != 0)
		return (1);
	return (0);
}

int	spell_two(const t_dict *d, int n, int *need_space)
{
	int	tens;
	int	ones;

	if (n < 20)
		return (write_num_word(d, n, need_space));
	tens = (n / 10) * 10;
	ones = n % 10;
	if (write_num_word(d, tens, need_space) != 0)
		return (1);
	if (ones > 0)
	{
		if (write_num_word(d, ones, need_space) != 0)
			return (1);
	}
	return (0);
}
