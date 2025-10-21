/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:27:14 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:26 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/* Goal: compute a / b and a % b into pointers. 
a and b are the input integers
div and mod are pointers to store the results
*div = a / b; calculates the quotient and stores
it at the address pointed by div
*mod = a % b; calculates the remainder and stores
it at the address pointed by mod
function to compute both the quotient and remainder of two integers
using pointers to return multiple values
ensure b is not zero before calling to avoid division by zero errors 
a / b — how many full boxes fit.
a % b — leftover marbles after packing.
Pitfall: division by zero (subject usually doesn’t ask to guard;
but know it’s undefined).*/ 