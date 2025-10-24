/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:40:53 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:41:12 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a = 1, b = 2;

	ft_putstr("Hello\n");
	ft_putchar('X');
	ft_putchar('\n');
	if (ft_strlen("abc") == 3)
		ft_putstr("len ok\n");
	if (ft_strcmp("abc", "abd") < 0)
		ft_putstr("cmp ok\n");
	ft_swap(&a, &b);
	if (a == 2 && b == 1)
		ft_putstr("swap ok\n");
	return (0);
}
