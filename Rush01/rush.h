/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:29:55 by mgee              +#+    #+#             */
/*   Updated: 2025/10/21 09:02:49 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h> /* write */
# include <stdlib.h> /* malloc, free */

/* I/O */
void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_putnbr(int n); /* 1..9 safe */
void	print_grid(int grid[4][4]);

/* Parsing */
int		parse_clues_4x4(const char *s, int out16[16]);

/* Duplicate checks on partial prefixes */
int		row_has_dup(int grid[4][4], int r, int upto_c);
int		col_has_dup(int grid[4][4], int c, int upto_r);

/* Visibility (called only when a row/col is complete) */
int		check_row_views(int grid[4][4], int r, int left, int right);
int		check_col_views(int grid[4][4], int c, int top, int bottom);

/* Solver */
int		solve_cell(int grid[4][4], int clues[16], int pos);

#endif
