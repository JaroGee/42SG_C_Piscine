/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:07:08 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 17:07:08 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h> // Only for printing expected result notes in comments (not used in your function)

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char a[12] = "Hello";
	unsigned int r1 = ft_strlcat(a, "World", 12);
	printf("Buf=12 | After:\"%s\" | Return:%u\n", a, r1);   // "HelloWorld", return 10

	char b[7] = "Hello";
	unsigned int r2 = ft_strlcat(b, "World", 7);
	printf("Buf=7  | After:\"%s\" | Return:%u\n", b, r2);   // "HelloW", return 10 (trunc)

	char c[5] = "Hello";        // Note: already full; no space for '\0' within size
	unsigned int r3 = ft_strlcat(c, "X", 5);
	printf("Buf=5  | After:\"%.*s\" | Return:%u\n", 5, c, r3); // may not be NUL inside 5, return 6

	char d[12] = "";
	unsigned int r4 = ft_strlcat(d, "abc", 12);
	printf("Buf=12 | After:\"%s\" | Return:%u\n", d, r4);   // "abc", return 3

	char e[1] = "";
	unsigned int r5 = ft_strlcat(e, "abc", 1);
	printf("Buf=1  | After:\"%.*s\" | Return:%u\n", 1, e, r5); // "", return 3
	return (0);
}

