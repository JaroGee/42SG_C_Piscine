/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:45:16 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 07:04:55 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/* Visit nodes exactly at the given remaining depth, left-to-right.
   ctx[0] = current level, ctx[1] = is_first flag (1/0). */
static void	apply_curr_level(t_btree *root, int rem, int ctx[2],
				void (*applyf)(void*, int, int))
{
	if (!root)
		return ;
	if (rem == 0)
	{
		applyf(root->item, ctx[0], ctx[1]);
		ctx[1] = 0;
		return ;
	}
	apply_curr_level(root->left, rem - 1, ctx, applyf);
	apply_curr_level(root->right, rem - 1, ctx, applyf);
}

void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int level, int is_first))
{
	int	h;
	int	lv;
	int	ctx[2];

	if (!root || !applyf)
		return ;
	h = btree_level_count(root);
	lv = 0;
	while (lv < h)
	{
		ctx[0] = lv;
		ctx[1] = 1;
		apply_curr_level(root, lv, ctx, applyf);
		lv++;
	}
}
