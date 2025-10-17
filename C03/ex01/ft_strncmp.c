/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:24:59 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 11:24:59 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
unsigned int i; — match the type of n to avoid signed/unsigned warnings.
if (n == 0) return 0; — comparing 0 chars means “treat as equal.”
while (...) && i + 1 < n — stop before copying/reading the (n+1)th char.
Cast to (unsigned char) on return — matches libc behavior for non-ASCII bytes. 
 * Compares up to n characters of two strings lexicographically.
 * Returns an integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 Goal: Compare two strings up to n characters.
Goal: Compare up to n characters.
Same as strcmp, but stop early if i == n.
Hints:
Use unsigned int i.
If n == 0, return 0.
Goal: Compare up to n chars of two C strings safely.
Return: Like strncmp — difference at first mismatch within n; 0 if first n eq.
Special: If n == 0, return 0.
Stop when: mismatch, '\0' in either, or i == n.
Edge cases: n=0; n smaller than first mismatch; early '\0' in one string.
Type: use unsigned int for n and index; cast to (unsigned char) on return is ideal.
Quick tests: ("abc","abd",2)→0; ("abc","abd",3)→neg; ("ab","abc",5)→neg.
*/
