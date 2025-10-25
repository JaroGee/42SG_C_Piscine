/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hundreds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:28 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 20:39:31 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_words_0_999(const t_dict *d, int n)
{
	int			h;
	int			r;
	int			need_space;
	char		key[4];

	if (n == 0)
		return ;
	h = n / 100;
	r = n % 100;
	need_space = 0;
	if (h > 0)
	{
		key[0] = (char)('0' + h);
		key[1] = '\0';
		print_word(dict_find(d, key), &need_space);
		print_word(dict_find(d, "100"), &need_space);
	}
	if (r > 0)
	{
		if (need_space)
			need_space = 1;
		print_words_0_99(d, r);
	}
}
