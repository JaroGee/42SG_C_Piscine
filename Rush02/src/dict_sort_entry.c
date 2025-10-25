/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_sort_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:47:12 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 01:47:15 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	swap_pairs(t_pair *a, t_pair *b)
{
	t_pair	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_pairs(t_dict *d)
{
	int	i;
	int	j;

	if (!d || d->size <= 1)
		return ;
	i = 0;
	while (i < d->size - 1)
	{
		j = 0;
		while (j < d->size - 1 - i)
		{
			if (ft_strcmp(d->pairs[j].key, d->pairs[j + 1].key) > 0)
				swap_pairs(&d->pairs[j], &d->pairs[j + 1]);
			j++;
		}
		i++;
	}
}
