/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 02:11:31 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 20:55:04 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int i;
	int *v;

	v = ft_range(-2, 3);
	if (!v)
		return (0);
	i = 0;
	while (i < 5)
	{
		printf("%d ", v[i]);
		i++;
	}
	printf("\n");
	free(v);
	return (0);
}
