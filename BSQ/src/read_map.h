/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ying <ying@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:39:52 by ying              #+#    #+#             */
/*   Updated: 2025/10/27 21:31:16 by ying             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "util_1.h"
#include "process_input.h"

#define BUFFER_SIZE 4096

void	ft_read_map(int fd);

void	ft_open_map(char *map);