/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:42:34 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 02:07:53 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static int	total_len(int size, char **strs, char *sep)
{
	int	i;
	int	t;

	if (size <= 0)
		return (1);
	t = 0;
	i = 0;
	while (i < size)
	{
		t += ft_strlen(strs[i]);
		i++;
	}
	t += ft_strlen(sep) * (size - 1);
	return (t + 1);
}

static void	copy_into(char *dst, char *src, int *pos)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[*pos] = src[i];
		(*pos)++;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	int		pos;
	char	*out;

	len = total_len(size, strs, sep);
	out = (char *)malloc(len * sizeof(char));
	if (!out)
		return (0);
	if (size <= 0)
	{
		out[0] = '\0';
		return (out);
	}
	pos = 0;
	i = 0;
	while (i < size)
	{
		copy_into(out, strs[i], &pos);
		if (i + 1 < size)
			copy_into(out, sep, &pos);
		i++;
	}
	out[pos] = '\0';
	return (out);
}
