/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:19:07 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 17:19:38 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_strdup_custom(char *src)
{
	int		len;
	int		i;
	char	*dst;

	len = ft_strlen(src);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	free_copies(t_stock_str *tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i].copy);
		i++;
	}
}

static int	set_slot(t_stock_str *slot, char *s)
{
	slot->size = ft_strlen(s);
	slot->str = s;
	slot->copy = ft_strdup_custom(s);
	if (slot->copy == 0)
		return (0);
	return (1);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		if (set_slot(&tab[i], av[i]) == 0)
		{
			free_copies(tab, i);
			free(tab);
			return (0);
		}
		i++;
	}
	tab[i].size = 0;
	tab[i].str = 0;
	tab[i].copy = 0;
	return (tab);
}
