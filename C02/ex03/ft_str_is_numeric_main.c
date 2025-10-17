/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric_main.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:01:58 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:54:18 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	char	*a = "123";
	char	*b = "1212A";
	char c = '0' +	ft_str_is_alpha(a);
	char d = '0' +	ft_str_is_alpha(b);
	  write(1, &c, 1); write(1, " ", 1); write(1, &d, 1); write(1, "\n", 1);
	  return(0);
}
