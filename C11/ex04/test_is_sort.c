/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:53:57 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:53:57 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_is_sort(int *tab, int length, int (*f)(int,int));
int cmp(int a,int b){ return a-b; }
void putchar1(char c){ write(1,&c,1); }

int main(void){
	int a1[]={1,2,2,3}, a2[]={3,2,1}, a3[]={1,3,2};
	putchar1(ft_is_sort(a1,4,cmp)+'0'); write(1," ",1);
	putchar1(ft_is_sort(a2,3,cmp)+'0'); write(1," ",1);
	putchar1(ft_is_sort(a3,3,cmp)+'0'); write(1,"\n",1);
	return 0;
}
