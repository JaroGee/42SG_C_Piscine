/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:29:46 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:59:31 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
{
		dest[i] =	src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* Goal: copy the string pointed to by src
(including the terminating '\0') to the buffer pointed to by dest.
dest is the destination buffer where the string will be copied
i src is the source string to be copied
i is an index to traverse the characters of the source string
while loop to iterate through each character of the source string
until the null terminator is reached
dest[i] = src[i]; copies each character from src to dest
after the loop, dest[i] = '\0'; adds the null terminator to the end
of the copied string in dest
return dest to provide the destination buffer
function to copy a string from src to dest
include necessary header for write	function(not used here but good practice)
strcpy — copy string including '\0'.
dest — address of the destination buffer.
src — address of the source string.
Loop until '\0' (the “end marker”).
Copy each character from src to dest.
Add '\0' at the end of dest.
Return dest.
Pitfall: forgetting to add the '\0' at the end of dest
(forget to terminate the string). */
