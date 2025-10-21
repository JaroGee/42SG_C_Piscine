/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:27:05 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:25 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
{
	write(1, &str[i], 1);
		i++;
	}
}

/* Goal: print a C-string (chars up to '\0') to stdout.
str is a pointer to the string to be printed
i is an index to traverse the string
while loop to iterate through each character of the string
until the null terminator is reached
write(1, &str[i], 1); writes one character at a
time to standard output (file descriptor 1)
function to print a string to standard output
include necessary header for write function
increment i to move to the next character in the string
str — address of the first character.
Loop until '\0' (the “end marker”).
write(1, &str[i], 1) — send one character to fd 1 (the screen).
Why write not printf? Project rules. <unistd.h> is allowed.
Pitfall: forgetting newline is fine; depends on test.*/