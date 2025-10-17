/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:07:10 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 17:07:10 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	i;

	len_d = 0;
	len_s = 0;
	while (dest[len_d] != '\0' && len_d < size)
		len_d++;
	while (src[len_s] != '\0')
		len_s++;
	if (size <= len_d)
		return (size + len_s);
	i = 0;
	while (src[i] != '\0' && (len_d + i + 1) < size)
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (len_d + len_s);
}

/*Goal: Let len_d = length(dest) and len_s = length(src).
If size <= len_d: no copying; return size + len_s (what we tried to build).
Else: copy at most size - len_d - 1 bytes from src to the end of dest,
NUL-terminate, and return len_d + len_s.
We compute len_d but cap it at size so we don’t read
past the buffer if dest wasn’t NUL-terminated within size.
Compute len_s fully (we’re not writing to src).
Case 1: size <= len_d → there is no room to append
(or dest wasn’t NUL within size), return size + len_s (BSD spec).
Case 2: We have room to copy up to size - len_d - 1 characters:
Copy while src[i] exists and we still have at least 1 byte left for '\0'.
Write the terminator at dest[len_d + i].
Return the length we tried to create: len_d + len_s.
Goal: Safely concatenate like BSD strlcat and return the length it tried to build.
Inputs: dest, src, total buffer size (capacity of dest).
Compute: len_d = min(index of NUL in dest, size), len_s = strlen(src).
If size <= len_d: no copy; return size + len_s (signals truncation).
Else: copy up to size - len_d - 1 chars from src, then NUL-terminate.
Return: len_d + len_s (intended final length, regardless of truncation).
Edge cases: size = 0; dest not NUL-terminated within size; tiny buffers; empty src.
Pass check if: both the post-string and return value match BSD strlcat.
Quick tests:
buf=12, dest="Hello", "World" → string "HelloWorld", return 10
buf=7, dest="Hello", "World" → string "HelloW", return 10 (trunc)
buf=1, dest="", "abc" → string "", return 3*/
