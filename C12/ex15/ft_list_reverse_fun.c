/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:08:17 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 06:16:24 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_list	*at(t_list *l, int i)
{
	while (i-- > 0 && l)
		l = l->next;
	return (l);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	t_list	*cur;
	t_list	*n1;
	t_list	*n2;
	void	*tmp;

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
		n1 = at(begin_list, i);
		n2 = at(begin_list, size - 1 - i);
		tmp = n1->data;
		n1->data = n2->data;
		n2->data = tmp;
		i++;
	}
}
