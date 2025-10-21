/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:07:35 by mgee              #+#    #+#             */
/*   Updated: 2025/10/21 10:49:58 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int i, int j, int k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (!(i == '7' && j == '8' && k == '9'))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				if (i != j && i != k && j != k)
				{
					ft_print(i, j, k);
					++k;
				}
			}
			++j;
		}
		++i;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}

/*
#include <unistd.h>

void	ft_print_comb(void);

int	main(void)
{
	write(1, "Expect starts with: 012, 013, 014, ...\nGot:             ", 57);
	ft_print_comb();
	write(1, "\n", 1);
	return (0);
}
*/
