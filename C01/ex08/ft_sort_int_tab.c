/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:44:02 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:25 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
{
		j = 0;
	while (j < size - i - 1)
{
	if(tab[j] > tab[j + 1])
{
				temp = tab[j];
				tab[j] =	tab[j + 1];
				tab[j + 1] =	temp;
			}
			j++;
		}
		i++;
	}
}

/* Goal: sort an int array	ascending(you can do a simple bubble sort).
temp to hold the value of tab[j] while we swap the values
i and j to track the positions in the array
outer loop to iterate through the array
inner loop to compare adjacent elements and swap if necessary
function to sort an array of integers in ascending order using bubble sort
tab is the array of integers
size is the number of elements in the array
i is the index for the outer loop
j is the index for the inner loop
temp is a temporary variable to facilitate the swap
increment j to move to the next pair of elements
increment i to move to the next pass through the array
if tab[j] is greater than tab[j + 1], swap them
initialize i and j indices
include necessary header for write	function(not used here but good practice)
Swap first ↔ last, second ↔ second-last, … until middle.
Analogy: flipping a queue from both ends inward.
Bubble pass moves larger values rightward by swapping neighbors.
Loop again while a pass performed at least one swap.
Complexity:	O(n²) is fine for learning.
Stability not required; correctness first.*/
