/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:51:34 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:51:34 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c){ write(1,&c,1); }
void	ft_putnbr(int n){ if(n<0){write(1,"-",1); n=-n;} if(n>9) ft_putnbr(n/10); ft_putchar('0'+(n%10)); }
int		*ft_map(int *tab, int length, int (*f)(int));
int		sq(int x){ return x*x; }

int main(void){
	int a[4]={1,2,3,4};
	int *b = ft_map(a,4,sq);
	for(int i=0;i<4;i++){ ft_putnbr(b[i]); write(1," ",1); }
	write(1,"\n",1); free(b); return 0;
}
