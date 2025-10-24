/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_string_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:57:52 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:57:52 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_sort_string_tab(char **tab);
void	putstr(char *s){ while(*s) write(1,s++,1); }

int main(void){
	char *t[]={"banana","apple","apricot","abc","z",0};
	ft_sort_string_tab(t);
	for(int i=0;t[i];i++){ putstr(t[i]); write(1,"\n",1); }
}
