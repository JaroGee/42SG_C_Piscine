/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 04:33:19 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 06:16:38 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*prev;
	t_list	*next;

	if (!begin_list)
		return ;
	prev = 0;
	cur = *begin_list;
	while (cur)
	{
		next = cur->next;
		if (cmp(cur->data, data_ref) == 0)
		{
			if (free_fct)
				free_fct(cur->data);
			if (prev)
				prev->next = next;
			else
				*begin_list = next;
			free(cur);
		}
		else
			prev = cur;
		cur = next;
	}
}
