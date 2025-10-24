/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:58:50 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 07:02:16 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/* visit only nodes at the given remaining depth, left-to-right */
static void	apply_curr_level(t_btree *root, int rem,
					t_bfs_ctx *ctx,
					void (*applyf)(void*, int, int))
{
	if (!root)
		return ;
	if (rem == 0)
	{
		applyf(root->item, ctx->level, ctx->first);
		ctx->first = 0;
		return ;
	}
	apply_curr_level(root->left, rem - 1, ctx, applyf);
	apply_curr_level(root->right, rem - 1, ctx, applyf);
}

void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int level, int is_first))
{
	int			h;
	int			lv;
	t_bfs_ctx	ctx;

	if (!root || !applyf)
		return ;
	h = btree_level_count(root);
	lv = 0;
	while (lv < h)
	{
		ctx.level = lv;
		ctx.first = 1;
		apply_curr_level(root, lv, &ctx, applyf);
		lv++;
	}
}
