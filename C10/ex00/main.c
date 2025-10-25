/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:35:01 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 09:09:58 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int	main(int argc, char **argv)
{
	int	ret;

	if (validate_args(argc))
		return (1);
	ret = display_file(argv[1]);
	return (ret);
}
