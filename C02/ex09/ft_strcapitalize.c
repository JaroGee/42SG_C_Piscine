/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:36:13 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:54:18 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alnum(char c)
{
	  return((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'));
}

char    *ft_strlowcase(char *str); /* we reuse ex08, or inline it */

char    *ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	  while(str[i] != '\0')
{
		  if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] =	str[i] - 'A' + 'a';
		  if(is_alnum(str[i]))
{
			  if(new_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] =	str[i] - 'a' + 'A';
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	  return(str);
}

/* Goal: capitalize the first letter of each word in a string.
A word is defined as a sequence of alphanumeric characters.
str is a pointer to the string to be modified
i is an index to traverse the string
new_word is a flag to indicate if the current character is
the start of a new word
while loop to iterate through each character of the string
until the null terminator is reached
if statement to convert uppercase letters to lowercase
if statement to check if the current character is alphanumeric
if new_word is true and the character is a lowercase letter,
convert it to uppercase
set new_word to false since we are now inside a word
else set new_word to true since the character is not alphanumeric
increment i to move to the next character in the string
return the modified string
function to capitalize the first letter of each word in a string
include helper function is_alnum to check for alphanumeric characters
reuse ft_strlowcase to convert the entire string to lowercase first
str — address of the first character.
Loop until '\0' (the “end marker”).
Use a flag to track if the current char is the start of a word.
If start of word and char is lowercase letter, make it uppercase.
If not start of word and char is uppercase letter, make it lowercase.
A word is a sequence of alphanumeric chars.
Non-alphanumeric chars separate words.
Empty string remains empty.
Pitfall: forgetting to reset the flag after non-alphanumeric chars.
Pitfall: forgetting to convert the whole string to lowercase first.
Alternative: inline the lowercase conversion instead of reusing ex08. */