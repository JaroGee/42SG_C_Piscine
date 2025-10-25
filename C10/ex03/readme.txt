ex03 — ft_hexdump (only -C)

What you’re building

A hexdump -C clone: shows bytes in hexadecimal plus an ASCII column with dots for non-printable characters, and keeps a running offset.

Analogy: Think of a warehouse:
	•	Offset = shelf number,
	•	Hex bytes = the exact SKU codes for each item,
	•	ASCII = the readable label (or . if unreadable).

Files to turn in:
ex03/
├── Makefile
├── main.c
├── hexdump.c
├── hexfmt.c
└── hex.h

Build & run:
bash

make
printf "Hello\nWorld" > t
./ft_hexdump -C t

You’ll see:
	•	Left: 8 hex digits offset (00000000, 00000010, …).
	•	Middle: 16 hex byte pairs, extra space after the 8th byte.
	•	Right: ASCII between | | (non-printable shown as .).
	•	Final line prints the total offset in hex.

Norm checklist
	•	Functions ≤25 lines.
	•	No ternary.
	•	Declarations at top.
	•	No assignment inside controls (we use read(...) in a loop with updates outside the condition).

⸻

Code walkthrough

hex.h
	•	Prototypes:
	•	put_hex8, put_hex2 – formatters.
	•	print_line – prints one 16-byte “row”.
	•	dump_fd – read a file descriptor and print rows while updating the offset.
	•	print_err – standard error helper.

hexfmt.c

put_hex8
	•	Converts a 32-bit offset to 8 hex characters.
	•	Writes the 8 chars at once.

put_hex2
	•	Converts a byte to 2 hex characters.

print_hex_cols (internal)
	•	Loops i = 0..15.
	•	For bytes that exist → print hex; else print spaces.
	•	Adds a space after every byte and one extra after byte 7.

print_ascii (internal)
	•	Loops bytes again.
	•	If printable (ASCII 32..126) → print the character; else print ..

print_line
	•	Calls put_hex8(base), a couple of spaces, then hex columns, then " |", ASCII, then "|\n".

hexdump.c

print_err
	•	Prints prog: path: <system error>.

dump_fd
	•	Reads up to 16 bytes at a time.
	•	Prints a line using the current off (offset).
	•	Increments off by the number of bytes read.

main.c

Flow
	•	off = 0;
	•	If first arg is -C, skip it.
	•	If no file args → read from stdin, then print the final total offset.
	•	Else for each file:
	•	Try to open; on failure print error.
	•	Dump; on dump error print error; close.
	•	Print total offset at the end.

⸻

Mental model
	•	We “walk” through the file 16 bytes at a time.
	•	Each step shows: where we are (offset), what the bytes are (hex), and how they look (ASCII).
