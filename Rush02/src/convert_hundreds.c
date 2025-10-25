/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hundreds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:28 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 01:37:18 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	spell_hundreds(const t_dict *d, int n, int *need_space)
{
	int	h;
	int	r;

	if (n < 100 || n > 999)
		return (0);
	h = n / 100;
	r = n % 100;
	if (h > 0)
	{
		spell_two(d, h, need_space);
		write_space_if_needed(need_space);
		write_word(dict_find(d, "100"));
	}
	if (r > 0)
		return (spell_two(d, r, need_space));
	return (0);
}
