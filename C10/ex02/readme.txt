ex02 — ft_tail (only -c N)

What you’re building

A subset of tail that prints the last N bytes of the input (file or -/stdin).

Analogy: You recorded a long football match; tail -c 10 jumps to the last 10 seconds of the video and plays just that part.

Files to turn in:
ex02/
├── Makefile
├── main.c
├── tail_utils.c
├── tail_read.c
└── tail.h

Build & run
bash

make
printf "abcdefg" > f
./ft_tail -c 3 f            # prints: efg
printf "XYZ" | ./ft_tail -c 2 -   # prints: YZ
./ft_tail -c 5 nosuch       # ft_tail: nosuch: No such file or directory

Norm checklist
	•	All functions ≤25 lines.
	•	No ternary.
	•	No assignment inside control conditions (we use read(...) > 0, which is fine).
	•	Declarations at top.

⸻

How it works (beginner-friendly)
	•	We keep a ring buffer of size N.
As bytes arrive, we overwrite the oldest byte. After reading everything, the buffer holds exactly the last N bytes.
	•	Then we print the content in the right order.

Analogy: A moving window over a long parade. The window only shows the last N people who passed by.

⸻

Code walkthrough

tail.h
	•	Prototypes:
	•	parse_count: parse the N after -c.
	•	run_tail_on_fd: read all from a file descriptor and print the last N bytes.
	•	print_err: helper to print prog: name: <system error>.

tail_utils.c

parse_count
	•	Reads digits only. Any non-digit → error.
	•	Stores the value into *out.

print_err
	•	Uses errno/strerror to show the system message.

tail_read.c

Internal: fill_buf
	•	Keeps a position index pos.
	•	For each byte read:
	•	ring[pos] = byte; pos = (pos + 1) % count;
	•	Counts total bytes seen (tot).
	•	Returns tot (how many bytes we read in total).

run_tail_on_fd
	•	Allocates a ring buffer of size count.
	•	Calls fill_buf(...) to populate it.
	•	If tot >= count:
	•	Print from pos to end, then from start to pos (wrap).
	•	Else:
	•	Print only tot bytes from the start (we never filled the ring).

main.c

Flow
	•	Validate: require -c N.
	•	If only 3 args (prog -c N) → read from stdin.
	•	Else loop over each path:
	•	If - → stdin.
	•	Else try open; on error print print_err.
	•	Call run_tail_on_fd(fd, count).
	•	Close if it was a file.

⸻

Mental model
	•	Ring buffer = circular shelf: when full, placing a new item kicks out the oldest one.
	•	After the stream ends, the shelf holds exactly the last N items.