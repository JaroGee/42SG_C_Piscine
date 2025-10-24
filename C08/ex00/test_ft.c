/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 02:36:02 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 02:36:08 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

void	ft_putchar(char c){ write(1, &c, 1); }
void	ft_putstr(char *s){ while (*s) write(1, s++, 1); }
int		ft_strlen(char *s){ int i=0; while (s[i]) i++; return i; }
int		ft_strcmp(char *a,char *b){ while(*a&&*a==*b){a++;b++;}return (unsigned char)*a-(unsigned char)*b; }
void	ft_swap(int *a,int *b){ int t=*a; *a=*b; *b=t; }

int main(void){
	int x=1, y=2;
	ft_swap(&x, &y);
	ft_putstr("x:"); ft_putchar('0'+x); ft_putstr(" y:"); ft_putchar('0'+y); ft_putchar('\n');
	return 0;
}
