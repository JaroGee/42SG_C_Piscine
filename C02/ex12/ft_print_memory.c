/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgee <mgee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:38:22 by mgee              #+#    #+#             */
/*   Updated: 2025/10/16 22:54:18 by mgee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	put_char(char c)
{	write(1, &c, 1); }

static void	put_str(char *s)
{	while(*s) write(1, s++, 1); }

static void	put_hex_addr(unsigned long n)
{
	char	buf[16];
	int	i = 16;
	  while(i--) buf[i] = '0';
	i = 15;
	  while(n)
{
		unsigned long	d = n % 16;
		  buf[i--] = "0123456789abcdef"[d];
		n /= 16;
	}
	  write(1, buf, 16);
}

static void	put_hex_byte(unsigned char c)
{
	char	b[2];
	b[0] = "0123456789abcdef"[c / 16];
	b[1] = "0123456789abcdef"[c % 16];
	  write(1, b, 2);
}

void    *ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i = 0;
	unsigned char *p = (unsigned char *)addr;

	  while(i < size)
{
		unsigned int	j = 0;
		  put_hex_addr((unsigned long)(p + i));
		  put_str(": ");
		  while(j < 16)
{
			  if(i + j < size)
				  put_hex_byte(p[i + j]);
			else
				  put_str("  ");
			  if(j % 2 == 1)
				  put_char(' ');
			j++;
		}
		j = 0;
		  while(j < 16 && i + j < size)
{
			unsigned char	c = p[i + j];
			  if(c >= 32 && c <= 126) put_char(c);
			else	put_char('.');
			j++;
		}
		  put_char('\n');
		i += 16;
	}
	  return(addr);
}

/* Goal: print memory content in a formatted way.
addr is a pointer to the start of the memory area to be printed
size is the number of bytes to print
i is an index to track the current byte being processed
p is a pointer to the memory area cast to unsigned char for byte-wise access
put_char is a helper function to write a single character to standard output
put_str is a helper function to write a string to standard output
put_hex_addr is a helper function to print an address in hexadecimal format
put_hex_byte is a helper function to print a byte in two-digit hexadecimal format
while loop to iterate through the memory area in chunks of 16 bytes
for each chunk, print the address, hexadecimal representation,
and ASCII representation
inner while loop to print the hexadecimal representation of each byte
if the byte is within the size limit, print its hexadecimal value
else print spaces to align the output
after every two bytes, print a space for readability
another while loop to print the ASCII representation of each byte
if the byte is a printable	character(ASCII 32 to 126), print it
else print a	dot(.) to represent non-printable characters
after processing 16 bytes, print a newline and move to the next chunk
return the original address pointer
function to print memory content in a structured format
include necessary header for write function
put_hex_addr — print an address in hexadecimal	format(16 chars).
put_hex_byte — print a byte in two-digit hexadecimal format.
ft_print_memory — print memory content in lines of 16 bytes:
- address in	hex(16 chars),
- hex	bytes(2 chars each, space every 2 bytes),
- ASCII	chars(printable or '.' for non-printable).
Loop until size bytes are printed.
If size is not multiple of 16, last line is partial.
Address is the pointer value of the first byte of the line.
Hex digits are '0'-'9', 'a'-'f'.
Printable chars are ASCII 32 to 126.
Each line ends with a newline.
Analogy: like a hex editor view of memory.
Pitfall: handling partial lines and non-printable chars.*/
/* Pitfall: ensuring address is printed as 16 hex digits. */
