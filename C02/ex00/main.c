/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 03:26:49 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 03:27:10 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src);

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	main(void)
{
	char	src[] = "42 is killing me!";
	char	buf[50];
	char	*ret;

	ret = ft_strcpy(buf, src);
	write(1, ret, ft_strlen(ret));
	write(1, "\n", 1);
	return (0);
}
