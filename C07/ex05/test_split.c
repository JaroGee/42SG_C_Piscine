/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 02:16:13 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 02:16:13 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	main(void)
{
	int		i;
	char	**v;

	v = ft_split("hi,,there::sg 42 piscine", ",: ");
	i = 0;
	while (v[i])
	{
		printf("[%s]\n", v[i]);
		free(v[i]);
		i++;
	}
	free(v);
	return (0);
}
