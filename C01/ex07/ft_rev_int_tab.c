/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:42:49 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:25 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	temp;

	start = 0;
	end = size - 1;
		  while(start < end)
{
		temp = tab[start];
		tab[start] =	tab[end];
		tab[end] =	temp;
		start++;
		end--;
	}
}

/* Goal: reverse an array of ints in place.
temp to hold the value of tab[start] while we swap the values
start and end to track the positions to swap
while loop to swap elements until the middle of the array is reached
function to reverse an array of integers in place
tab is the array of integers
size is the number of elements in the array
start is the index of the beginning of the array
end is the index of the end of the array
temp is a temporary variable to facilitate the swap
increment start and decrement end to move towards the center
if start is less than end, continue swapping
swap the elements at the start and end indices
initialize start and end indices
include necessary header for write	function(not used here but good practice)
Swap first ↔ last, second ↔ second-last, … until middle.
Analogy: flipping a queue from both ends inward.
Boundaries: use size - 1 - i.
No extra	arrays(in-place) */
