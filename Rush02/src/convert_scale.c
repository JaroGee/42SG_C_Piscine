/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:35 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 20:39:38 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	print_scale_word(const t_dict *d, unsigned long long scale)
{
	char	key[32];
	int		i;
	int		j;

	i = 0;
	key[i++] = '1';
	j = 0;
	while (j < (int)scale)
	{
		key[i++] = '0';
		j++;
	}
	key[i] = '\0';
	print_word(dict_find(d, key), &(int){1});
}

void	print_scaled(const t_dict *d, unsigned long long n)
{
	unsigned long long	div;
	int					chunk;

	if (n == 0)
	{
		print_word(dict_find(d, "0"), &(int){0});
		return ;
	}
	div = 1000000000000000000ULL;
	while (div > 0)
	{
		chunk = (int)((n / div) % 1000);
		if (chunk)
		{
			print_words_0_999(d, chunk);
			if (div >= 1000ULL)
				print_scale_word(d, (unsigned long long)ft_scale_zeros(div));
		}
		div /= 1000ULL;
	}
}
