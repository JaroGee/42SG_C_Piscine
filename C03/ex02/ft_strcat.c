/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:25:54 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 11:29:59 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*
 * Walk dest to find its end (i stops at the '\0').
Copy src chars to dest starting at i, using j to index src.
After loop, write the final '\0' at dest[i + j].
Return dest so it can be used directly in expressions.
 * Appends the src string to the dest string,
 overwriting the terminating null byte
 * at the end of dest, and then adds a terminating null byte.
 * Returns a pointer to the resulting string dest.
 Goal: Concatenate two strings.
 Goal: Append src at the end of dest.
Steps:
Find end of dest (loop until '\0').
Copy characters from src to that position.
Add final '\0'.
Return dest.
Goal: Append src to end of dest and return dest.
Find: end of dest, then copy all of src including final NUL.
Terminate: ensure dest ends with '\0'.
Caller must: provide a large enough dest buffer.
Edge cases: src="" (no change except NUL rewrite); dest="" (becomes src).
Do not: read/write past buffer; allocate memory.
Quick tests: dest="Hi", src="!"→"Hi!"; dest="Hi", src=""→"Hi". */
