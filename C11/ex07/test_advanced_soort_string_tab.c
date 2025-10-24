/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_advanced_soort_string_tab.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:58:26 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:58:26 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char*,char*));
int		mycmp(char *a,char *b){ int i=0; while(a[i]&&b[i]&&a[i]==b[i]) i++; return (unsigned char)a[i]-(unsigned char)b[i]; }
void	putstr(char *s){ while(*s) write(1,s++,1); }

int main(void){
	char *t[]={"zz","aa","ab","a",0};
	ft_advanced_sort_string_tab(t, mycmp);
	for(int i=0;t[i];i++){ putstr(t[i]); write(1,"\n",1); }
}
