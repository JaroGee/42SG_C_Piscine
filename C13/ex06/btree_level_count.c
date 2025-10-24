/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:45:13 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 06:58:22 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	btree_level_count(t_btree *root)
{
	int	lh;
	int	rh;

	if (!root)
		return (0);
	lh = btree_level_count(root->left);
	rh = btree_level_count(root->right);
	return (1 + max(lh, rh));
}
