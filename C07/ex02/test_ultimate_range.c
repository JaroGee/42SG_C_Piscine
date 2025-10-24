/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ultimate_range.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 02:12:39 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 02:12:46 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int *p;
	int n;
	int i;

	n = ft_ultimate_range(&p, 5, 9);
	printf("n=%d -> ", n);
	i = 0;
	while (i < n)
	{
		printf("%d ", p[i]);
		i++;
	}
	printf("\n");
	free(p);
	return (0);
}
