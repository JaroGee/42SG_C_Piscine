/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:41:07 by mgee              +#+    #+#             */
/*   Updated: 2025/10/22 18:43:47 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	base_value(char c, char *base)
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

/* advances i past whitespace and signs; returns sign (+1 or -1) */
static int	skip_ws_and_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	val;
	int	res;
	int	b_len;

	if (!is_valid_base(base))
		return (0);
	b_len = 0;
	while (base[b_len])
		b_len++;
	i = 0;
	res = 0;
	sign = skip_ws_and_sign(str, &i);
	val = base_value(str[i], base);
	while (val != -1)
	{
		res = res * b_len + val;
		i++;
		val = base_value(str[i], base);
	}
	return (res * sign);
}

/*
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	printf("%d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("-101010", "01"));
	return (0);
}
*/