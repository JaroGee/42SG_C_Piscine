/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 02:10:34 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 02:10:37 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char *a = ft_strdup("hello");
	char *b = ft_strdup("");
	printf("[%s]\n[%s]\n", a, b);
	free(a);
	free(b);
	return (0);
}
