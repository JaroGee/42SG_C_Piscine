/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_lookup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:34:55 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 14:50:03 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

const char	*dict_find(const t_dict *d, const char *key)
{
	int	i;

	i = 0;
	while (i < d->size)
	{
		if (ft_strcmp(d->pairs[i].key, key) == 0)
			return (d->pairs[i].val);
		i++;
	}
	return (NULL);
}
