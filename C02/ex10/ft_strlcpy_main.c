/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:08:51 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:54:18 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

void	putnbr(unsigned int n)
{
	char	c;
	  if(n >= 10) putnbr(n / 10);
	c = '0' + (n % 10);
	  write(1, &c, 1);
}

int	slen(char *s)
{ int i=0; while(s[i]) i++; return i; }

int	main(void)
{
	char	buf[5];
	unsigned int len =	ft_strlcpy(buf, "abcdef", 5);
	  write(1, buf, slen(buf));
	  write(1, " ", 1);
	  putnbr(len);
	  write(1, "\n", 1);
	  return(0);
}
