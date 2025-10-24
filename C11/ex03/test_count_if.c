/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_count_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:53:25 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:53:25 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int		ft_count_if(char **tab, int length, int (*f)(char *));
int		len_gt3(char *s){ int n=0; while(s[n]) n++; return n>3; }
void	putnbr(int n){ if(n>9) putnbr(n/10); char c='0'+(n%10); write(1,&c,1); }

int main(void){
	char *v[]={"a","bb","cccc","ddddd","ee",0};
	int r = ft_count_if(v, 5, len_gt3);
	putnbr(r); write(1,"\n",1); return 0;
}
