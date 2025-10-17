/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:31:19 by mgee              #+#    #+#             */
/*   Updated: 2025/10/17 01:20:26 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/* Goal: copy up to n characters from the string pointed to by src
(including the terminating '\0' if it fits) to the buffer pointed to by dest.
dest is the destination buffer where the string will be copied
src is the source string to be copied
n is the maximum number of characters to copy
i is an index to traverse the characters of the source string
first while loop to copy characters from src to dest
until either n characters are copied or the null terminator is reached
second while loop to fill the remaining space in dest with null characters
if the length of src is less than n
return dest to provide the destination buffer
function to copy up to n characters from src to dest
include necessary header for write	function(not used here but good practice)
strncpy — copy up to n chars from src to dest.
dest — address of the destination buffer.
src — address of the source string.
n — maximum number of characters to copy.
Loop until n or '\0' (the “end marker”).
Copy each character from src to dest.
If there’s space	left(overrun), pad with '\0'.
Return dest.
Pitfall: forgetting to add the '\0' padding if src is shorter than n
(forget to terminate the string if there’s space). */
