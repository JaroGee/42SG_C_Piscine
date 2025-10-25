/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:38:50 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 20:38:53 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	key_len(const char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	dict_sort(t_dict *d)
{
	int		i;
	int		swapped;
	t_pair	tmp;

	if (!d || d->size <= 1)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i + 1 < d->size)
		{
			if (key_len(d->pairs[i].key) > key_len(d->pairs[i + 1].key))
			{
				tmp = d->pairs[i];
				d->pairs[i] = d->pairs[i + 1];
				d->pairs[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}
