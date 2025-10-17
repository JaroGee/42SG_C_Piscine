/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:37:18 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:40:26 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void put_hex(unsigned char c)
{
    char *base = "0123456789abcdef";
    char out[2];

    out[0] = base[c / 16];
    out[1] = base[c % 16];
    write(1, out, 2);
}

void    ft_putstr_non_printable(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        unsigned char c = (unsigned char)str[i];
        if (c < 32 || c == 127)
        {
            write(1, "\\", 1);
            put_hex(c);
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}

/* Goal: print a string, replacing non-printable characters
with a backslash followed by their two-digit hexadecimal value.
printable characters are those with ASCII values from 32 to 126 inclusive.
str is a pointer to the string to be printed
i is an index to traverse the string
put_hex is a helper function to convert a character to its
two-digit hexadecimal representation and print it
while loop to iterate through each character of the string
until the null terminator is reached
cast the current character to unsigned char to handle
non-printable characters correctly
if statement to check if the character is non-printable
if the character's ASCII value is less than 32 or equal to 127,
print a backslash and call put_hex to print its hexadecimal value
else print the character as is
increment i to move to the next character in the string
function to print a string with non-printable characters in hex format
include necessary header for write function
put_hex — convert a char to two hex digits and print them.
ft_putstr_non_printable — print a string, replacing non-printable
chars with \ followed by two hex digits.
Loop until '\0' (the “end marker”).
Check if each char is in 32-126 range.
If a char is out of range, print \ and its hex value.
If a char is in range, print it as is.
Hex digits are '0'-'9', 'a'-'f'.
Use integer division and modulo to get the two hex digits.
Analogy: reading a book and spelling out unprintable words as hex codes.
Pitfall: forgetting to cast char to unsigned char before processing.
Pitfall: off-by-one errors in hex conversion.
Pitfall: not handling the null terminator correctly. */