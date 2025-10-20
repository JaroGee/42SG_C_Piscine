/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 03:24:32 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 03:45:07 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	src[] = "42 is killing me!";
	char	dest[50];
	int		i;

	ft_strcpy(dest, src);

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

/*char *ft_strcpy(char *dest, char *src)
Function takes two pointers: where to copy to and where to copy from.
Returns dest (same as the real strcpy).
int i; i = 0; — Index for walking through the characters.
while (src[i] != '\0') — Loop until we hit the string terminator.
dest[i] = src[i]; i++; — Copy each character, then move forward.
After the loop, dest[i] = '\0'; — Add the final NUL terminator to dest.
return (dest); — Return pointer to the start of dest.*/