/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:09:16 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 06:16:39 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*node;
	t_list	*cur;

	if (!begin_list)
		return ;
	node = ft_create_elem(data);
	if (!node)
		return ;
	if (!*begin_list || cmp((*begin_list)->data, data) > 0)
	{
		node->next = *begin_list;
		*begin_list = node;
		return ;
	}
	cur = *begin_list;
	while (cur->next && cmp(cur->next->data, data) <= 0)
		cur = cur->next;
	node->next = cur->next;
	cur->next = node;
}
