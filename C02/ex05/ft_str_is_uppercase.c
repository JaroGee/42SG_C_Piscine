/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 05:22:04 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 07:55:44 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
			return (0);
		i++;
	}
	return (1);
}


#include <unistd.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char	str1[] = "AAAAAAA";
	char	str2[] = "bbbbbbbb";
	char	str3[] = "";
    char    str4[] = "ABCD123";
    char    str5[] = "XaaaYZ!";
	char	c;

	c =	ft_str_is_lowercase(str1) + '0';
	  write(1, &c, 1);
	  write(1, "\n", 1);

	c =	ft_str_is_lowercase(str2) + '0';
	  write(1, &c, 1);
	  write(1, "\n", 1);

	c =	ft_str_is_lowercase(str3) + '0';
	  write(1, &c, 1);
	  write(1, "\n", 1);

    c =  ft_str_is_lowercase(str4) + '0';
      write(1, &c, 1);
      write(1, "\n", 1);

    c =  ft_str_is_lowercase(str5) + '0';
      write(1, &c, 1);
      write(1, "\n", 1);

	  return(0);
}
*/