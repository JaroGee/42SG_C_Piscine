/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:12:07 by mgee              +#+    #+#             */
/*   Updated: 2025/10/25 09:12:12 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEX_H
# define HEX_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

void	put_hex8(unsigned long v);
void	put_hex2(unsigned char b);
void	print_line(unsigned long base, unsigned char *buf, int len);
int		dump_fd(int fd, unsigned long *off);
void	print_err(const char *prog, const char *path);

#endif