/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:36:42 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:54:18 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;
	  while(src[src_len] != '\0')
		src_len++;
	  if(size == 0)
		  return(src_len);
	  while(i + 1 < size && src[i] != '\0')
{
		dest[i] =	src[i];
		i++;
	}
	  dest[i] = '\0';
	  return(src_len);
}

/* Goal: copy a string from src to dest, ensuring not to exceed size - 1 characters,
and null-terminate dest. Return the length of src.
dest is a pointer to the destination string where src will be copied
src is a pointer to the source string to be copied
size is the maximum number of characters to copy, including the null terminator
i is an index to traverse the strings
src_len is the length of the source string
while loop to calculate the length of src by iterating
through each character until the null terminator is reached
if statement to handle the case where size is 0
if size is 0, return the length of src without copying anything
while loop to copy characters from src to dest
the loop continues until i + 1 is less than	size(to leave space for the null
terminator) and until the end of src is reached
inside the loop, copy the character from src to dest and increment i
after the loop, add a null terminator to dest at index i
return the length of src
function to copy a string with size limit and return src length
include necessary header for write	function(not used here but good practice)
strlcpy — copy up to size - 1 chars from src to dest, NUL
terminate dest.
Return the length of	src(not the length copied).
If size is 0, return length of	src(no chars copied).
If src length >= size, dest is truncated.
dest must be large enough to hold size chars.
Analogy: filling a	cup(dest) from a bottle (src) with a limit (
size).
Pitfall: forgetting to leave space for the null terminator.
Pitfall: returning the length of dest instead of src.*/
/* Pitfall: not handling size == 0 case. */
/* Pitfall: off-by-one error in the copy loop condition. */
/* Pitfall: not null-terminating dest when size > 0. */
/* Pitfall: not calculating src length correctly. */
/* Pitfall: modifying src or dest pointers directly instead of using an index. */
/* Pitfall: not considering the case when src is shorter than size - 1. */
/* Pitfall: not using unsigned int for size and indices, leading to potential
negative values. */
/* Pitfall: not returning the correct value when size is less than or equal to
the length of src. */
/* Pitfall: not initializing variables properly. */
/* Pitfall: not including necessary headers for standard	functions(if any). */