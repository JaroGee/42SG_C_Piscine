/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:41:09 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:25 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_a;
	int	temp_b;

	  if(*b != 0)
{
		temp_a = *a;
		temp_b = *b;
		*a = temp_a / temp_b;
		*b = temp_a % temp_b;
	}
}

/* Goal: same as ex03 but modify the values in place through pointers.
a and b are pointers to the integers to be divided
temp_a and temp_b to hold the original values of *a and *b
check if *b is not zero to avoid division by zero errors
* a = temp_a / temp_b; calculates the quotient
and stores it at the address pointed by a
* b = temp_a % temp_b; calculates the remainder
and stores it at the address pointed by b
function to compute both the quotient and remainder of two integers in place
using pointers to modify the original integers
ensure b is not zero before performing division to avoid undefined behavior
a / b — how many full boxes fit.
a % b — leftover marbles after packing.
Compute using originals, then overwrite *a with quotient and *b with remainder.
Analogy: you write results back into the same two boxes you received.
Pitfall: division by	zero(subject usually doesn’t ask to guard;
but know it’s undefined). */