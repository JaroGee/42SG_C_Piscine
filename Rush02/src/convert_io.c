/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:09 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 20:39:12 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>

static void	putspace(void)
{
	write(1, " ", 1);
}

void	print_word(const char *s, int *need_space)
{
	if (!s || !*s)
		return ;
	if (*need_space)
		putspace();
	ft_putstr(s);
	*need_space = 1;
}
