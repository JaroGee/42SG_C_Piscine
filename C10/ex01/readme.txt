ex01 — ft_cat

What you’re building

A simplified cat that prints files to standard output,
and supports - to read from standard input.

Analogy: Like a photocopier: place a page (a file) or hold
the page to the camera (stdin) and it reproduces the content 
on the output tray (your screen).

Files to turn in:
ex01/
├── Makefile
├── main.c
├── cat.c
└── cat.h

Build & run:
bash

make
./ft_cat                     # reads from keyboard until Ctrl-D
./ft_cat a.txt b.txt
./ft_cat - a.txt < input.txt
./ft_cat no_such_file       # prints: ft_cat: no_such_file: <system error>

Norm checklist
	•	Functions ≤25 lines.
	•	- means “use stdin”.
	•	Clear error prints using errno/strerror.
	•	No ternary; declarations at top.

⸻

Code walkthrough

cat.h
	•	Includes used by both files.
	•	Declares:
	•	splice_fd(int fd) – copy bytes from given fd to stdout.
	•	print_err(const char *prog, const char *path) – print prog: path: <system error>.

cat.c

splice_fd
	•	Biggish buffer (e.g., 28672 bytes) for efficient copies.
	•	Outer loop: read into buffer while positive.
	•	Inner loop: write everything read (may take multiple writes).
	•	Return 1 if write fails, else 0.
Analogy: Fill box with apples, then move all apples to another table; repeat.

print_err
	•	Uses strerror(errno) to translate system error number into human text.
	•	Prints to stderr: prog: path: message.

main.c

Helpers for clarity
	•	handle_stdin(prog): run splice_fd(0), print error if needed.
	•	handle_file(prog, path): open file, splice, close, print errors as needed.

Flow
	•	prog = basename(argv[0]) – shows the program’s short name in errors.
	•	If no args → handle_stdin.
	•	Else loop over args:
	•	If arg is "-" → handle_stdin.
	•	Else → handle_file(prog, arg).

⸻

Mental model
	•	This is ft_display_file on steroids: multiple files + stdin support + cleaner errors.
	•	Still: Read → Write in chunks, until done.
