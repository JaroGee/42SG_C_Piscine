ex00 — ft_display_file

What you’re building (in human words)

A tiny command-line tool that prints a file’s contents to the screen.

Analogy: Imagine you’re reading a note aloud. ft_display_file is the friend that takes the paper (file) and reads it out loud onto the terminal.

Goals & why this exists
	•	Learn to open/read/close files safely.
	•	Practice robust error messages.
	•	Practice 42 Norm: tiny functions, clear structure, no forbidden patterns.

Files you’ll turn in:
ex00/
├── Makefile
├── main.c
├── display.c
└── display.h

Build & run:
bash

make
./ft_display_file path/to/file


Common checks:
bash

./ft_display_file                # -> "File name missing."
./ft_display_file a b            # -> "Too many arguments."
./ft_display_file no_such_file   # -> "Cannot read file."

Norm checklist you pass
	•	≤25 lines per function.
	•	Variables declared at top of function.
	•	No assignments inside if(...) or while(...).
	•	One blank line after declarations.
	•	No ternary operator.

⸻

Code walkthrough (line-by-line mindset)

display.h
	•	#ifndef / #define / #endif – standard header guard.
	•	Includes only what we actually use.
	•	Declares 2 functions:
	•	validate_args(int argc) – checks argument count; prints user-friendly messages.
	•	display_file(const char *path) – opens, reads, and prints a file.

display.c

Helper: putstr2
	•	Loops through a C string, writing each char to stderr (fd 2).
Analogy: You speak each letter into the error microphone.

Helper: dump_fd
	•	Creates a fixed buffer (char buf[4096])—a “bucket”.
	•	read fills the bucket; inner loop writes the exact bytes read.
	•	If any write fails, return error (1).
	•	Reads until read returns 0 (end of file).
Analogy: Keep scooping water from a tank and pouring it into a sink until the tank’s empty.

validate_args
	•	If no file given → “File name missing.”
	•	If >1 file given → “Too many arguments.”
	•	Otherwise OK.

display_file
	•	Tries to open in read-only mode.
	•	On failure → “Cannot read file.”
	•	On success → dump_fd(fd); close; if dump_fd failed, print error.

main.c
	•	Calls validate_args.
	•	If valid, calls display_file(argv[1]).
	•	Returns program exit status (0 on success, 1 on failure).

⸻

Mental model
	•	Open → Read chunks → Write chunks → Close
	•	Errors are friendly and exact.
