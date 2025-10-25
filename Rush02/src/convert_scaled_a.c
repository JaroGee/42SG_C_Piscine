/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_scaled_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:40:19 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 23:51:40 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

const char	*scale_for_group(int group)
{
	if (group == 1)
		return ("1000");
	if (group == 2)
		return ("1000000");
	if (group == 3)
		return ("1000000000");
	if (group == 4)
		return ("1000000000000");
	if (group == 5)
		return ("1000000000000000");
	if (group == 6)
		return ("1000000000000000000");
	return (0);
}
