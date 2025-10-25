/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:34:54 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 20:40:18 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	convert_number(const t_dict *d, const char *num)
{
	unsigned long long	n;
	int					len;

	len = ft_strlen(num);
	if (len == 0)
		return ;
	if (len <= 3)
	{
		n = ft_atoull(num);
		if (n == 0)
			ft_putstr(dict_find(d, "0"));
		else
			print_words_0_999(d, (int)n);
		return ;
	}
	n = ft_atoull(num);
	print_scaled(d, n);
}
