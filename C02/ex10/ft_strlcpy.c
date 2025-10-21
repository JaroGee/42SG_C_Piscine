/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 05:22:13 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 08:22:36 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/*
#include <unistd.h>
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

void	putstr(char *s)
{
    int i=0;
    while(s[i])
    {
        write(1,&s[i],1);
        i++;
    } 
    write(1,"\n",1);
}
void	putnbr(unsigned int n)
{
    if (n > 9) putnbr(n/10);
    char c = (n%10)+'0'; write(1,&c,1);
}

int	main(void)
{
	char	dst[10];
	unsigned int n = ft_strlcpy(dst, "Hello 42!", 10);
	putstr(dst);
	putnbr(n);
    write(1, "\n", 1);
	return (0);
}
*/