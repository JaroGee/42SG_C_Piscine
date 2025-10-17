/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable_main.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:22:34 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:54:18 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	s[] = "Hi\t42\nOK\x7F!";
	  ft_putstr_non_printable(s); /* prints: Hi\09 42\0a OK\7f! (without spaces) */
	  write(1, "\n", 1);
	  return(0);
}
