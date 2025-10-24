/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 03:54:49 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 03:54:56 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	op_add(int a, int b)
{
	return (a + b);
}

int	op_sub(int a, int b)
{
	return (a - b);
}

int	op_mul(int a, int b)
{
	return (a * b);
}

int	op_div(int a, int b)
{
	return (a / b);
}

int	op_mod(int a, int b)
{
	return (a % b);
}
