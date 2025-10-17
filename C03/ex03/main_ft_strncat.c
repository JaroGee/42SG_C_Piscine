/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strncat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:06:49 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 17:06:49 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char buf[32] = "Hello";
	printf("Case 1\nBefore: %s\n", buf);
	ft_strncat(buf, "World", 5);
	printf("After : %s\n\n", buf);   // "HelloWorld"

	char buf2[32] = "Hello";
	printf("Case 2\nBefore: %s\n", buf2);
	ft_strncat(buf2, " World", 0);
	printf("After : %s\n\n", buf2);  // "Hello" (no change)

	char buf3[32] = "Hi";
	printf("Case 3\nBefore: %s\n", buf3);
	ft_strncat(buf3, " there!", 20);
	printf("After : %s\n", buf3);    // "Hi there!"
	return (0);
}

