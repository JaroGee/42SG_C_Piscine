/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:34:51 by mgee              +#+    #+#             */
/*   Updated: 2025/10/26 01:43:15 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

/*==============================*/
/*           TYPES              */
/*==============================*/

typedef struct s_pair
{
	char	*key;
	char	*val;
}	t_pair;

typedef struct s_dict
{
	t_pair	*pairs;
	int		size;
}	t_dict;

/*==============================*/
/*         STR UTILITIES        */
/*==============================*/

int			ft_strlen(const char *s);
int			ft_strcmp(const char *a, const char *b);
char		*ft_strdup(const char *s);
void		*ft_memcpy(void *dst, const void *src, int n);

/*==============================*/
/*         FILE UTILITIES       */
/*==============================*/

char		*slurp(const char *path);

/*==============================*/
/*       NUM VALIDATION         */
/*==============================*/

int			validate_num(const char *s);

/*==============================*/
/*        DICT UTILITIES        */
/*==============================*/

const char	*dict_find(const t_dict *d, const char *key);
void		sort_pairs(t_dict *d);
void		free_dict(t_dict *d);

/*==============================*/
/*         DICT PARSING         */
/*==============================*/

int			pass1_count_pairs(char *buf);
int			parse_lines_into_pairs(char *buf, t_dict *out);
int			parse_dict(const char *path, t_dict *out);
char		*trim_spaces(char *s);

/*==============================*/
/*       CONVERSION HELPERS     */
/*==============================*/

int			write_word(const char *s);
int			write_space_if_needed(int *need_space);
int			spell_two(const t_dict *d, int n, int *need_space);
int			spell_hundreds(const t_dict *d, int n, int *need_space);
int			spell_chunk_with_scale(const t_dict *d, int chunk,
				const char *scale, int *need_space);
const char	*scale_for_group(int group);

/*==============================*/
/*         MAIN CONVERTER       */
/*==============================*/

int			print_words(const t_dict *d, const char *digits);

/*==============================*/
/*       CONVERT ADAPTERS       */
/*==============================*/

int			ft_putstr(const char *s);
int			print_words_0_999(const t_dict *d, int n);
void		print_scaled(const t_dict *d, unsigned long long n);

unsigned long long	ft_atoull(const char *s);

#endif