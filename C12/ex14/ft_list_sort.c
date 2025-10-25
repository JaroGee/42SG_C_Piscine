/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:08:01 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 06:16:39 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*cur;
	void	*swap;
	int		sorted;

	if (!begin_list || !*begin_list)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		cur = *begin_list;
		while (cur->next)
		{
			if (cmp(cur->data, cur->next->data) > 0)
			{
				swap = cur->data;
				cur->data = cur->next->data;
				cur->next->data = swap;
				sorted = 0;
			}
			cur = cur->next;
		}
	}
}
