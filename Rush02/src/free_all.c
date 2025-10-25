/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:34:55 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 14:50:10 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_dict(t_dict *d)
{
	int	i;

	if (!d || !d->pairs)
		return ;
	i = 0;
	while (i < d->size)
	{
		free(d->pairs[i].key);
		free(d->pairs[i].val);
		i++;
	}
	free(d->pairs);
	d->pairs = NULL;
	d->size = 0;
}
