/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:47:33 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 01:47:36 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_words(const t_dict *d, const char *digits)
{
	unsigned long long	n;

	if (!digits || !*digits)
		return (-1);
	if (validate_num(digits) != 0)
		return (-1);
	n = ft_atoull(digits);
	if (n < 1000ULL)
		return (print_words_0_999(d, (int)n));
	print_scaled(d, n);
	return (0);
}
