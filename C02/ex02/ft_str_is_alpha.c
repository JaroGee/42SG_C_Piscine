/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:32:13 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:38:25 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_str_is_alpha(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= 'a' && str[i] <= 'z')))
            return (0);
        i++;
    }
    return (1);
}

/* Goal: check if the string contains only alphabetic characters.
str is a pointer to the string to be checked
i is an index to traverse the string
while loop to iterate through each character of the string
until the null terminator is reached
if statement to check if the current character is not
an uppercase or lowercase letter
if a non-alphabetic character is found, return 0
increment i to move to the next character in the string
if the loop completes without finding non-alphabetic characters, return 1
function to check if a string contains only alphabetic characters
include necessary header for write	function(not used here but good practice)
str — address of the first character.
Loop until '\0' (the “end marker”).
Check if each char is in 'A'-'Z' or 'a'-'z'.
If a char is out of range, return 0.
If all chars are in range, return 1.
Empty string returns 1 (no out-of-range chars).
Pitfall: forgetting to check both uppercase and lowercase letters.*/