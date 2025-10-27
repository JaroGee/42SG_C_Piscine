/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 02:57:57 by mgee              +#+    #+#             */
/*   Updated: 2025/10/27 17:07:56 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}		t_stock_str;

t_stock_str	*ft_strs_to_tab(int ac, char **av);
void		ft_show_tab(t_stock_str *par);

#endif