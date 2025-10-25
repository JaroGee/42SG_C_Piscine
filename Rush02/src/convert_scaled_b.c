/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_scaled_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:43:37 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 23:51:08 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	spell_chunk_with_scale(
		const t_dict *d, int chunk, const char *scale, int *need_space)
{
	if (chunk <= 0)
		return (0);
	if (spell_hundreds(d, chunk, need_space) != 0)
		return (1);
	if (scale)
	{
		if (write_space_if_needed(need_space) != 0)
			return (1);
		if (write_word(dict_find(d, scale)) != 0)
			return (1);
	}
	return (0);
}
