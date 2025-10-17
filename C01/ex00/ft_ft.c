/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:41:01 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:26 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/*Goal: set the int pointed to by nbr to 42.
int *nbr — “pointer to an int”. Think of it like a house address for a number.
*nbr = 42; — go to that address and put the number 42 inside the mailbox.
a pointer holds a location, not the value; *nbr dereferences to the actual value.
Common pitfall: forgetting the * when assigning.
don't forget the "*" */