/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:42:38 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 20:55:04 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_base_len(char *base)
{
	int	used[256];
	int	i;

	i = 0;
	while (i < 256)
	{
		used[i] = 0;
		i++;
	}
	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13)
			|| used[(unsigned char)base[i]])
			return (0);
		used[(unsigned char)base[i]] = 1;
		i++;
	}
	return (i);
}

int	ft_index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long	ft_atoi_base(char *s, char *base, int blen)
{
	long	sign;
	long	val;
	int		idx;

	sign = 1;
	val = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	while (*s)
	{
		idx = ft_index_in_base(*s, base);
		if (idx < 0)
			break ;
		val = val * blen + idx;
		s++;
	}
	return (val * sign);
}

/* helper to compute how many chars we need */
static int	count_len(long n, int blen)
{
	long	nb;
	int		len;

	len = 0;
	if (n <= 0)
	{
		len++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb /= blen;
		len++;
	}
	return (len);
}

/* now safely under 25 lines */
char	*ft_itoa_base(long n, char *base, int blen)
{
	long	nb;
	int		len;
	int		i;
	char	*out;

	len = count_len(n, blen);
	out = (char *)malloc(len + 1);
	if (!out)
		return (0);
	out[len] = '\0';
	nb = n;
	if (nb < 0)
		nb = -nb;
	if (n < 0)
		out[0] = '-';
	i = len - 1;
	if (nb == 0)
		out[i--] = base[0];
	while (nb > 0)
	{
		out[i--] = base[nb % blen];
		nb /= blen;
	}
	return (out);
}
