/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:34:57 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 14:39:15 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	run_with_dict(const char *dict_path, const char *num)
{
	t_dict	d;

	if (parse_dict(dict_path, &d))
		return (write(1, "Dict Error\n", 11), 1);
	if (validate_num(num))
		return (write(1, "Error\n", 6), free_dict(&d), 1);
	print_words(&d, num);
	free_dict(&d);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (run_with_dict("dicts/numbers.dict", argv[1]));
	else if (argc == 3)
		return (run_with_dict(argv[1], argv[2]));
	write(1, "Error\n", 6);
	return (1);
}
