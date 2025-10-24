/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:43:30 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:53:33 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc_ok;
	int	desc_ok;

	if (length <= 2)
		return (1);
	asc_ok = 1;
	desc_ok = 1;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			asc_ok = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			desc_ok = 0;
		i++;
	}
	return (asc_ok || desc_ok);
}
