/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:26:22 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 11:28:40 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char buf[32] = "Hello";
	printf("Before: %s\n", buf);
	ft_strcat(buf, " ");
	ft_strcat(buf, "World!");
	printf("After : %s\n", buf);  // "Hello World!"
	return (0);
}

