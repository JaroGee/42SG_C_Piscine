/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:36:56 by mgee              +#+    #+#             */
/*   Updated: 2025/10/18 11:36:56 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	int clues[16];
	int grid[4][4];
	int r, c;

	if (argc != 2 || !parse_clues_4x4(argv[1], clues))
	{
		ft_putstr("Error\n");
		return (0);
	}
	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			grid[r][c] = 0;
			c++;
		}
		r++;
	}
	if (solve_cell(grid, clues, 0))
		print_grid(grid);
	else
		ft_putstr("Error\n");
	return (0);
}

/*
Purpose
This is the entry point. It:
Reads and validates command-line input.
Initializes a 4×4 grid with zeros.
Calls the backtracking solver.
Prints the result or "Error\n" if unsolvable.
Key functions used:
parse_clues_4x4: Parses and validates the clues from input.
solve_cell: The backtracking solver function.
print_grid: Outputs the solved grid.

if (argc != 2 || !parse_clues_4x4(argv[1], clues))
	ft_putstr("Error\n");
→ Validates input format and number of clues.
Then it zeros the grid:
(r=0; r<4; r++) (c=0; c<4; c++) grid[r][c] = 0;
Finally, it attempts to solve and print:
if (solve_cell(grid, clues, 0))
if (solve_cell(grid, clues, 0))
	print_grid(grid);
else
	ft_putstr("Error\n");
→ Calls the solver and prints the grid if successful; otherwise prints "Error\n"
main.c handles setup and error checking. The actual solving happens in solve.c
and all helper logic is abstracted to keep main.c clean.
*/