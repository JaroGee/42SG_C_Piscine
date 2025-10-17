/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:06:48 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 17:06:48 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*Find the end of dest with i.
Start copying from src using j, but stop when:
you hit src’s terminator, or
you’ve copied nb characters (j < nb).
Always place a '\0' after the last copied character.
Return dest.
Goal: Append at most nb chars from src to dest; NUL-terminate; return dest.
Copy rule: copy while src[j] and j < nb.
Terminate: always write one final '\0'.
Caller must: ensure dest has room for min(nb, len(src)) + 1.
Edge cases: nb=0 (no change); nb > len(src) (acts like full strcat).
Quick tests: ("Hello","World",3)→"HelloWor"; ("Hi","",5)→"Hi"; ("Hi"," there",0)→"Hi".*/
