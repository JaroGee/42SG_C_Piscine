/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 02:15:22 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 20:07:47 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	char *s;

	s = ft_convert_base("   -1A3", "0123456789ABCDEF", "01");
	printf("%s\n", s);
	free(s);
	return (0);
}
