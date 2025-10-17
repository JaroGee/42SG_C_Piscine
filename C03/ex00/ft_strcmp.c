/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:23:46 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 11:30:56 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
int ft_strcmp(char *s1, char *s2) —
function returns an int indicating lexicographic order.
int i; — index for walking both strings in lockstep.
i = 0; — start at the first character.
while (...) — keep advancing while neither ended and chars match.
return (s1[i] - s2[i]);
first differing chars decide the sign; if both '\0', returns 0. 
 * Compares two strings lexicographically.
 * Returns an integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
Goal: Compare two strings.
Return:
< 0 if s1 < s2
0 if they’re equal
> 0 if s1 > s2
Notes:
Loop until you find a mismatch or hit '\0'.
Return the difference s1[i] - s2[i].
Goal: Implement lexicographic comparison of two C strings.
Return: s1[i] - s2[i] at first mismatch; 0 if identical.
Stop when: You hit a mismatch or either '\0'.
Edge cases: empty vs non-empty ("" vs "a"), identical strings, early mismatch.
Do not: use <string.h>; allocate memory.
Pass check if: outputs match libc’s strcmp sign behavior (neg/zero/pos).
Quick tests: "abc","abc"→0; "abc","abd"→neg"; "abd","abc"→pos"; "",""→0; "","a
*/
