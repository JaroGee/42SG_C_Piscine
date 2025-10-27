/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 02:14:15 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 20:55:04 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char *arr[] = {"SG", "42", "Piscine"};
	char *s = ft_strjoin(3, arr, " - ");
	printf("%s\n", s);
	free(s);
	return (0);
}
