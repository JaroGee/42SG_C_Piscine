/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:42:39 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 20:55:04 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_sep(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *s, char *set)
{
	int	i;
	int	in;
	int	cnt;

	i = 0;
	in = 0;
	cnt = 0;
	while (s[i])
	{
		if (is_sep(s[i], set))
			in = 0;
		else if (!in)
		{
			in = 1;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

static char	*dup_range(char *s, int a, int b)
{
	int		len;
	int		i;
	char	*w;

	len = b - a;
	w = (char *)malloc((len + 1) * sizeof(char));
	if (!w)
		return (0);
	i = 0;
	while (i < len)
	{
		w[i] = s[a + i];
		i++;
	}
	w[i] = '\0';
	return (w);
}

static void	fill_split(char **out, char *str, char *set)
{
	int	i;
	int	start;
	int	idx;

	i = 0;
	start = -1;
	idx = 0;
	while (str[i])
	{
		if (!is_sep(str[i], set) && start < 0)
			start = i;
		if ((is_sep(str[i], set) || str[i + 1] == '\0') && start >= 0)
		{
			if (is_sep(str[i], set))
				out[idx++] = dup_range(str, start, i);
			else
				out[idx++] = dup_range(str, start, i + 1);
			start = -1;
		}
		i++;
	}
	out[idx] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**out;
	int		words;

	words = count_words(str, charset);
	out = (char **)malloc((words + 1) * sizeof(char *));
	if (!out)
		return (0);
	fill_split(out, str, charset);
	return (out);
}
