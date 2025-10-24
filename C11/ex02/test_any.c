/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:52:27 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:52:27 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int		ft_any(char **tab, int (*f)(char *));
int		has_a(char *s){ for(int i=0;s[i];i++) if(s[i]=='a') return 1; return 0; }
void	putchar1(char c){ write(1,&c,1); }

int main(void){
	char *v[]={"hello","world","singapore",0};
	int r = ft_any(v, has_a);
	putchar1(r?'1':'0'); putchar1('\n'); return 0;
}
