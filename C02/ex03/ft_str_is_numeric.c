/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:32:59 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:25 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_str_is_numeric(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

/* Goal: check if the string contains only numeric characters.
str is a pointer to the string to be checked
i is an index to traverse the string
while loop to iterate through each character of the string
until the null terminator is reached
if statement to check if the current character is not a digit
if a non-numeric character is found, return 0
increment i to move to the next character in the string
if the loop completes without finding non-numeric characters, return 1
function to check if a string contains only numeric characters
include necessary header for write	function(not used here but good practice)
str — address of the first character.
Loop until '\0' (the “end marker”).
Check if each char is in '0'-'9'.
If a char is out of range, return 0.
If all chars are in range, return 1.
Empty string returns 1 (no out-of-range chars).
Pitfall: forgetting to check the full range of digits. */