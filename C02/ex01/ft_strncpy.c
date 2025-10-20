/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 03:57:08 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 04:39:49 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	else
		dest[n - 1] = '\0';
	return (dest);
}

/*
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	src[] = "Hello 42!";
	char	dest[20];
	unsigned int	i;

	ft_strncpy(dest, src, 5);

	i = 0;
	while (dest[i] != '\0')
{
	write(1, &dest[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
*/
