/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:07:02 by mgee              +#+    #+#             */
/*   Updated: 2025/10/17 17:07:02 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (0);
}

/*if (to_find[0] == '\0') return (str);
 * empty needle: by spec, return the whole haystack.
i walks str from left to right.
For each i, reset j = 0 and compare str[i + j]
with to_find[j] until mismatch or to_find ends.
If we consumed all of to_find (to_find[j] == '\0'),
we found a match → return pointer into str at i.
If we finish scanning str without success, return 0 (NULL).
Goal: Return pointer to first occurrence of to_find inside str; else 0.
Empty needle: if to_find == "", return str.
Search: for each i in str, check if to_find matches from i.
Return type: char * pointing into str (not a new allocation).
Edge cases: needle longer than haystack; multiple matches → return the first.
Quick tests: ("abcabc","abc")→&str[0];
("abcabc","bca")→&str[1]; ("abc","")→str; ("abc","x")→0.
*/
