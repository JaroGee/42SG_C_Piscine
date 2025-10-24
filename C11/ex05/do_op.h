/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:54:18 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:54:23 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_atoi(const char *s);

int		op_add(int a, int b);
int		op_sub(int a, int b);
int		op_mul(int a, int b);
int		op_div(int a, int b);
int		op_mod(int a, int b);

#endif
