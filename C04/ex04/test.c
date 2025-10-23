/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 06:53:36 by mgee              +#+    #+#             */
/*   Updated: 2025/10/23 06:57:14 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void point(int *there)
{
    *there = 42;
}

void point(int *there);

int main(void)\

{
int value;

    point(&value);
    printf("%d\n", value);
    return (0);
}