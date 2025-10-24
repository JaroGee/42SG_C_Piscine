/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:08:17 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 06:53:30 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_list	*at(t_list *l, int i)
{
	while (i-- > 0 && l)
		l = l->next;
	return (l);
}

static void	swap_data_at(t_list *head, int i, int j)
{
	t_list	*n1;
	t_list	*n2;
	void	*tmp;

	n1 = at(head, i);
	n2 = at(head, j);
	tmp = n1->data;
	n1->data = n2->data;
	n2->data = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	t_list	*cur;

	size = 0;
	cur = begin_list;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	i = 0;
	while (i < size / 2)
	{
		swap_data_at(begin_list, i, size - 1 - i);
		i++;
	}
}
