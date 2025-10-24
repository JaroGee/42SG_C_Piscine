/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:09:41 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 06:16:43 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(
			t_list **begin_list1,
			t_list *begin_list2,
			int (*cmp)()
		)
{
	t_list	*cur;

	if (!begin_list1)
		return ;
	cur = begin_list2;
	while (cur)
	{
		ft_sorted_list_insert(begin_list1, cur->data, cmp);
		cur = cur->next;
	}
}
