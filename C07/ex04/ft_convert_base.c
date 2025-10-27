/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:42:37 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 20:55:04 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_base_len(char *base);
long	ft_atoi_base(char *str, char *base, int blen);
char	*ft_itoa_base(long n, char *base, int blen);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		blf;
	int		blt;
	long	val;

	blf = ft_base_len(base_from);
	blt = ft_base_len(base_to);
	if (blf == 0 || blt == 0)
		return (0);
	val = ft_atoi_base(nbr, base_from, blf);
	return (ft_itoa_base(val, base_to, blt));
}
