/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:43:06 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:44:37 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* Check if a character is part of the charset (separator) */
static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* Count how many words exist in the string */
static int	count_words(char *str, char *charset)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

/* Duplicate a word (copy n characters into a new malloc string) */
static char	*dup_word(char *str, int n)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* Main split function */
char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		k;
	int		len;

	result = (char **)malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
		{
			len = 0;
			while (str[i + len] && !is_sep(str[i + len], charset))
				len++;
			result[k++] = dup_word(&str[i], len);
			i += len;
		}
	}
	result[k] = NULL;
	return (result);
}
