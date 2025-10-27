/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 02:10:34 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 19:57:58 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*src1 = "Hello 42!";
	char	*src2 = "";
	char	*src3 = "Malloc and free are friends.";
	char	*dup;

	dup = ft_strdup(src1);
	printf("src : %s\n", src1);
	printf("copy: %s\n\n", dup);
	free(dup);

	dup = ft_strdup(src2);
	printf("src : \"%s\"\n", src2);
	printf("copy: \"%s\"\n\n", dup);
	free(dup);

	dup = ft_strdup(src3);
	printf("src : %s\n", src3);
	printf("copy: %s\n", dup);
	free(dup);

	return (0);
}