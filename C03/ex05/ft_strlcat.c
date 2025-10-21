/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:48:10 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 08:48:10 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	i;

	slen = ft_strlen(src);
	dlen = 0;
	while (dlen < size && dest[dlen] != '\0')
		dlen++;
	if (dlen == size)
		return (size + slen);
	i = 0;
	while (src[i] != '\0' && dlen + i + 1 < size)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}

/*
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	buf[12] = "Hello";
	unsigned int	ret;

	ret = ft_strlcat(buf, " World!", sizeof(buf));
	printf("buf : '%s'\n", buf);
    // truncated or full depending on size
	printf("ret : %u\n", ret);
    // intended total length: initial dest len + src len

	char	small[8] = "Hello";
	ret = ft_strlcat(small, " World!", sizeof(small));
	printf("buf : '%s'\n", small);
    // truncated to fit
	printf("ret : %u\n", ret);
    // tells total length attempted
	return (0);
}
*/