/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:28:00 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:25 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/* Goal: return string	length(not counting '\0').
str is a pointer to the string whose length is to be calculated
len is a counter to keep track of the number of characters in the string
while loop to iterate through each character
of the string until the null terminator is reached
increment len for each character encountered
return len to provide the length of the string
function to compute the length of a string
include necessary header for write	function(not used here but good practice)
str — address of the first character.
Loop until '\0' (the “end marker”).
Count characters as you go.
Return the count.
Pitfall: forgetting to count the last character
before '\0' (the loop condition handles this
correctly).
Count characters until the end marker.
Off-by-one vigilance; don’t count '\0'*/