/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:46:38 by mgee              +#+    #+#             */
/*   Updated: 2025/10/23 15:00:15 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	printf("%d\n", ft_strncmp("abcdef", "abcxyz", 3));  // 0
	printf("%d\n", ft_strncmp("abcdef", "abcxyz", 4));  // <0
	printf("%d\n", ft_strncmp("abcd", "ab", 10));       // >0
	printf("%d\n", ft_strncmp("ab", "abcd", 10));       // <0
	printf("%d\n", ft_strncmp("same", "same", 0));      // 0
	return (0);
}
*/