/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:34:54 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 14:49:52 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_words(const t_dict *d, const char *digits)
{
	int	n;

	n = atoi(digits);
	if (n == 0)
		return (write_word(dict_find(d, "0")), 0);
	if (n < 1000)
		return (spell_hundreds(d, n, &(int){0}));
	if (n < 1000000)
	{
		spell_hundreds(d, n / 1000, &(int){0});
		write_word(dict_find(d, "1000"));
		if (n % 1000)
			spell_hundreds(d, n % 1000, &(int){1});
		return (0);
	}
	if (n < 1000000000)
	{
		spell_hundreds(d, n / 1000000, &(int){0});
		write_word(dict_find(d, "1000000"));
		if (n % 1000000)
			spell_hundreds(d, n % 1000000, &(int){1});
		return (0);
	}
	write(1, "Dict Error\n", 11);
	return (1);
}
