RUSH 02 — Number to Words Converter (C Piscine Project)

Project Purpose

Rush 02’s goal is to create a C program that reads a
dictionary file (numbers.dict) and converts a numeric
string into its corresponding English words.

Example:
$ ./rush-02 123
one hundred twenty three

This project is about handling parsing, validation, and output formatting using only pure C, while ensuring:
	•	Modularity and clean structure
	•	Memory safety (no leaks)
	•	Compliance with Norminette standards

⸻

Project Structure

includes/
 rush02.h → header file containing all structs and function prototypes

src/
 main.c → handles CLI arguments and program flow
 parse_dict.c → loads and parses the dictionary file
 parse_pass1.c → reads the file and splits into lines
 parse_lines.c → extracts and validates key-value pairs
 str_trim.c → trims whitespace
 str_utils.c → contains ft_strlen, ft_strcmp, ft_strdup
 io_utils.c → provides slurp() for reading the entire file
 num_validate.c → checks input validity (only digits allowed)
 dict_lookup.c → retrieves words from the dictionary
 dict_sort.c → sorts entries for efficiency
 free_all.c → frees all allocated memory
 convert_main.c → main conversion logic
 convert_io.c → ensures proper spacing
 convert_two.c → handles numbers 0–99
 convert_hundreds.c → handles numbers 100–999
 convert_scale.c → handles numbers ≥1000

dicts/
 numbers.dict → text dictionary used for lookups

Makefile → build rules
README.md → documentation

⸻

Compilation

make re → rebuild everything
make clean → remove object files
make fclean → remove objects and binaries

⸻

Running the Program

Using the default dictionary:
./rush-02 123

Using a custom dictionary:
./rush-02 dicts/numbers.dict 999

Expected results:
./rush-02 0 → zero
./rush-02 5 → five
./rush-02 13 → thirteen
./rush-02 219 → two hundred nineteen
./rush-02 1005 → one thousand five
./rush-02 1234567 → one million two hundred thirty four thousand five hundred sixty seven

⸻

Exercise Goals
	•	Reinforce modular programming practices
	•	Learn file I/O operations in C
	•	Manage heap memory safely
	•	Implement a custom dictionary parser
	•	Write custom string functions without <string.h>
	•	Keep functions short and clean for Norminette
	•	Separate logic into clear, testable units

⸻

Header File Explanation (rush02.h)

Data Structures

typedef struct s_pair {
 char *key;
 char *val;
} t_pair;

typedef struct s_dict {
 t_pair *pairs;
 int size;
} t_dict;

Each dictionary line (for example, 100 : hundred) becomes a t_pair.
The dictionary (t_dict) dynamically stores all pairs in memory.

⸻

Functions and Why They Exist

int parse_dict(const char *path, t_dict *out);
Loads the dictionary into memory and validates its format.

void free_dict(t_dict *d);
Centralized cleanup for all allocated pairs and strings.

int validate_num(const char *s);
Ensures user input is numeric and non-empty before conversion.

const char *dict_find(const t_dict *d, const char *key);
Looks up and returns the word corresponding to a numeric key.

void print_words_0_99(const t_dict *d, int n);
Converts numbers 0–99 into words using dictionary lookups.

void print_words_0_999(const t_dict *d, int n);
Handles hundreds by combining the tens and units logic.

void print_scaled(const t_dict *d, unsigned long long n);
Handles large numbers (thousands, millions, billions) by chunking digits.

int ft_strlen(const char *s);
int ft_strcmp(const char *a, const char *b);
char *ft_strdup(const char *s);
Basic string utilities to avoid the standard C library and maintain consistent behavior.

char *str_trim(char *s);
Removes leading and trailing whitespace from dictionary entries.

char *slurp(const char *path);
Reads the entire file into a single buffer for parsing.

⸻

Why the Program Is Split into Layers

Layer 1: 0–99 (convert_two.c)

Handles the unique English patterns below one hundred:
	•	0–19 are direct words (“zero” to “nineteen”)
	•	20–90 are tens words (“twenty”, “thirty”, …)
	•	Adds units if needed (“twenty one”)

Layer 2: 0–999 (convert_hundreds.c)

Adds the “hundred” logic:
	•	For example, 305 → “three hundred five”
	•	Reuses the 0–99 printer for the remainder

Layer 3: Scaled Numbers (convert_scale.c)

Breaks large numbers into groups of three digits (thousands, millions, billions):
	•	Example: 1,234,567 → groups [1][234][567]
	•	Prints: “one million two hundred thirty four thousand five hundred sixty seven”
	•	Uses the dictionary for scale words (“thousand”, “million”)

This three-step design mirrors English number grammar and keeps each function short and simple.

⸻

Parsing Logic Explained
	1.	Read the dictionary file with slurp().
The file is stored in memory as one continuous string.
	2.	Split the buffer into lines.
Each line should follow the pattern:
<number> : <word>
	3.	Trim each line and validate both sides.
The left side must contain digits only.
The right side must be a printable word.
	4.	Store each valid entry as a t_pair inside t_dict.
	5.	Optionally sort the dictionary by key length to ensure proper order.
	6.	The program now uses this dictionary for all conversions.

This approach is memory efficient (one malloc for buffer + pairs) and keeps parsing clean and linear (O(n)).

⸻

Why a Custom Dictionary Is Necessary
	•	Avoids hardcoding words into the program
	•	Allows multi-language support (English, French, etc.)
	•	Makes it easy to adjust phrasing (for example, adding “and” for British style)
	•	Lets you expand up to any number scale (“trillion”, “quadrillion”, etc.)
	•	Keeps the logic modular: the parser doesn’t care what language or format you use as long as it follows the “number : word” pattern

Minimum required keys:
0–19, 20,30,40,50,60,70,80,90, 100, 1000, 1000000, 1000000000

⸻

Program Flow Summary

Start
→ Read command-line arguments
→ If 1 argument, use default dictionary
→ If 2 arguments, use provided dictionary
→ Parse dictionary with parse_dict()
→ Validate number with validate_num()
→ If invalid, print “Error”
→ If dictionary fails, print “Dict Error”
→ If number == 0, print “zero”
→ Else, determine which function to use:
	•	If length ≤ 3 → print_words_0_999()
	•	Else → print_scaled()
→ Print newline
→ Free dictionary
→ Exit cleanly

⸻

Troubleshooting

“Error” → Non-numeric input or incorrect arguments
“Dict Error” → Dictionary missing, unreadable, or improperly formatted
Incorrect words → Verify spacing and syntax in numbers.dict
No output → Ensure Makefile compiled successfully and binary exists

⸻

Example Output

./rush-02 0 → zero
./rush-02 19 → nineteen
./rush-02 100 → one hundred
./rush-02 219 → two hundred nineteen
./rush-02 1005 → one thousand five
./rush-02 999999 → nine hundred ninety nine thousand nine hundred ninety nine


RUSH-02 — FULL ANNOTATED WALKTHROUGH (PER FILE) + OPERATOR’S MANUAL

Overview
This document explains how every source file in the project
works, with a detailed, line-by-line walkthrough where your
posted code is known, and a precise step sequence for the
remaining modules (so your teammates can map each step to
the corresponding lines in their local files). It ends
with a separate, practical “how to operate” manual.

Directory layout (expected)
includes/rush02.h
dicts/numbers.dict
src/main.c
src/str_utils.c
src/str_trim.c
src/io_utils.c
src/num_validate.c
src/parse_pass1.c
src/parse_lines.c
src/parse_dict.c
src/dict_sort.c
src/dict_lookup.c
src/free_all.c
src/convert_io.c
src/convert_two.c
src/convert_hundreds.c
src/convert_scale.c
src/convert_main.c

==============================
HEADER

includes/rush02.h — purpose and interface map
Lines 1–2: Header guard opens. Prevents double inclusion.
Lines 4–7: Standard headers: unistd.h (write, read, close), stdlib.h (malloc, free), fcntl.h (open), stddef.h (size_t).
Lines 9–14: typedef struct s_pair { char *key; char *val; } t_pair;
A dictionary entry: numeric string (key) mapped to word (val).
Lines 16–21: typedef struct s_dict { t_pair *pairs; int size; } t_dict;
Holds a heap array of pairs and the count.
Lines 25–31 (STR UTILITIES):
int ft_strlen(const char *s); integer length (we keep int to satisfy prior interface).
int ft_strcmp(const char *a, const char *b); lexicographic compare.
char *ft_strdup(const char *s); heap duplicate.
Lines 35–38 (FILE UTILITIES): char *slurp(const char *path); read whole file into a buffer.
Lines 42–45 (NUM VALIDATION): int validate_num(const char *s); returns 0 if OK, non-zero if invalid.
Lines 49–54 (DICT UTILITIES):
const char *dict_find(const t_dict *d, const char *key);
void sort_pairs(t_dict *d);
void free_dict(t_dict *d);
Lines 58–64 (DICT PARSING):
int pass1_count_pairs(char *buf);
int parse_lines_into_pairs(char *buf, t_dict *out);
int parse_dict(const char *path, t_dict *out);
char *trim_spaces(char *s);
Lines 68–76 (CONVERSION HELPERS):
int write_word(const char *s);
int write_space_if_needed(int *need_space);
int spell_two(const t_dict *d, int n, int *need_space);
int spell_hundreds(const t_dict *d, int n, int *need_space);
int spell_chunk_with_scale(const t_dict *d, int chunk, const char *scale, int *need_space);
const char *scale_for_group(int group);
Lines 80–83 (MAIN CONVERTER): int print_words(const t_dict *d, const char *digits);
Lines 85–86: Header guard closes.

==============================
CORE UTILITIES

src/str_utils.c — you posted this file; here’s a true line-by-line
Line 1–13: 42 header comment (meta info).
Line 15: #include “rush02.h” brings prototypes and std headers transitively.

Lines 17–33: void *ft_memcpy(void dst, const void src, int n)
17: Function signature; custom memcpy with int n to match our interfaces elsewhere.
19–21: Local variables: i (loop index), d (byte pointer to dst), s (byte pointer to src).
23–24: Cast the generic void to unsigned char for byte-wise copy.
25: i = 0; initialize loop.
26–30: Copy n bytes one by one.
31: Return original dst pointer.

Lines 35–44: int ft_strlen(const char *s)
37: i = 0; loop index.
38–39: Iterate until NUL; increment i.
40–43: Return number of non-NUL chars.

Lines 46–55: int ft_strcmp(const char *a, const char *b)
48: i = 0; loop index.
49–50: Scan while both strings match and not at NUL.
51–53: Return difference of unsigned char at first mismatch (or zero if both ended).

Lines 57–76: char *ft_strdup(const char *s)
59: len = ft_strlen(s).
60: copy = malloc(len + 1); allocate new buffer including terminator.
61–62: If malloc failed, return NULL.
63: i = 0; start copying.
64–68: Copy characters until NUL.
69: Terminate the new string.
70–75: Return pointer.

Design note: Using int (not size_t) keeps Norme and header consistent across the project.

src/str_trim.c — trimming helper
What’s in this file (typical lines you’ll see and what they do):
1: #include “rush02.h”
3–5: static int is_space(int c) — returns true for ’ ’, ‘\t’, ‘\r’, ‘\v’, ‘\f’.
7–28: char *trim_spaces(char *s)
• Save original start pointer (p = s).
• Advance p while is_space(*p) — skip leading whitespace.
• If *p == ‘\0’ return p (string is all spaces).
• Find end: q = p + ft_strlen(p) - 1; then while (q >= p && is_space(*q)) { *q = ‘\0’; q–; }
• Return p, which now points at first non-space char with trailing spaces nulled off.

Why it matters: parse_lines.c depends on trim_spaces to accept lines with loose spacing in the dictionary.

src/io_utils.c — you posted the logic; here’s a line-by-line
1–13: 42 header comment.
15: #include “rush02.h”

17–35: static char *grow(char *old, int oldsz, int newsz)
17: Private helper to expand a dynamic buffer.
19–21: Local vars: tmp (new buffer), i (counter).
23–25: tmp = malloc(newsz); if fail, return 0 (NULL).
26: i = 0.
27–31: Copy oldsz bytes from old to tmp.
32–33: If old != NULL, free(old).
34: Return tmp.

37–74: char *slurp(const char *path)
39–45: Locals: fd (file descriptor), buf (dynamic buffer), cap (capacity),
len (current length), r (read count), tmp[1024] (stack chunk).
47–49: fd = open(path, O_RDONLY); on failure return 0.
50–54: Initialize buf = 0, cap = 0, len = 0; perform first read: r = read(fd, tmp, 1024).
55–68: while (r > 0)
• If len + r + 1 > cap, increase capacity to len + r + 1 + 1024
(room for terminator + headroom) and grow().
• On grow failure, break (buf will be NULL if first grow failed).
• Copy r bytes from tmp to buf + len using ft_memcpy.
• len += r; read next chunk into tmp.
69: close(fd).
70–71: If no buffer and len == 0 (read failed from the start), return 0.
72–73: If buf exists, add NUL terminator at buf[len].
74: Return buf.

Notes:
• No assignment inside control structures (respecting Norme).
• Grow strategy keeps lines ≤80 chars and functions ≤25 lines by splitting logic into grow() and slurp().

src/num_validate.c — input checker
What’s in this file and how it flows:
1: #include “rush02.h”
3–19: static int is_all_digits(const char *s)
• Reject NULL or empty.
• Scan char by char; if any char not in ‘0’–‘9’, return 0.
• Return 1 if all digits.
21–45: int validate_num(const char *s)
• Reject NULL.
• Optionally skip one leading ‘+’ (depending on your chosen rules).
• Ensure remaining string is digits and not empty (call is_all_digits).
• Return 0 for valid, non-zero for invalid (e.g., 1).
Rationale: converter assumes a canonical digits-only string downstream.

src/str_utils.c already covered above.

==============================
DICTIONARY PARSING

src/parse_pass1.c — “how many pairs should we allocate?”
Typical exact sequence (map to lines in your file):
1: #include “rush02.h”
3–18: static int has_colon(char *s)
• Walk s until ‘:’ or ‘\n’ or ‘\0’; return 1 if colon found on the line, else 0.
20–44: int pass1_count_pairs(char *buf)
• i = 0; count = 0; start = 0.
• Walk the buffer; when you see ‘\n’, temporarily consider one
line terminated at that index and call has_colon(buf + start).
• If has_colon, increment count; move start to i + 1; continue.
• At end, if the last line has no trailing newline, run has_colon on the trailing segment.
• Return count (0 if none or on malformed buffer you might choose to return 0 to signal failure).

src/parse_lines.c — you pasted the version that passes Norme; here’s a true line-by-line
1: #include “rush02.h”

3–17: static int store_key_val(char *line, t_dict *out, int idx)
4–5: char *key; char *val; local pointers.
7: key = trim_spaces(line); now key begins at first non-space.
8: val = trim_spaces(line + ft_strlen(key) + 1);
jump past key+\0 (split later) and trim value.
9–10: if (!*key || !*val) return (0); ignore blank pairs.
11–12: duplicate both strings into out->pairs[idx].key/val.
13–14: if either malloc failed, return (-1) to abort parsing.
15–16: return (1) meaning “stored”.

19–33: static int handle_line(char *s, t_dict *out, int *pidx)
21: i = 0; scan current line ‘s’.
22–24: while (s[i] && s[i] != ‘:’) i++; find the first colon.
25–26: if no colon, return 0 (skip this line).
27: s[i] = ‘\0’; in-place split: key string ends here, value begins at s + i + 1.
28–29: call store_key_val; if returns < 0, bubble up error.
30–31: increment *pidx: we stored exactly one pair (store_key_val returned 1).
32: return 0 (success).

35–56: int parse_lines_into_pairs(char *buf, t_dict *out)
37–39: int i = 0, start = 0, idx = 0; i scans buffer,
start marks start of current line, idx is write index into out->pairs.
40–51: while (buf[i]) { if (buf[i] == ‘\n’) { buf[i] = ‘\0’;
if (handle_line(buf + start, out, &idx) < 0) return (-1); start = i + 1; } i++; }
• Replace ‘\n’ with ‘\0’ to create an in-place C string for the line.
• Send the line to handle_line.
• Advance start to begin of next line.
52–53: At EOF, if there is a trailing line without newline, handle it as well.
54–55: out->size = idx; return 0.

src/parse_dict.c — you posted this file; here’s a true line-by-line
1–13: 42 header comment.
15: #include “rush02.h”

17–23: static int init_out(t_dict *out)
18–21: Initialize out->pairs = 0; out->size = 0; return 0.
This makes the function idempotent and safe for early returns.

25–52: int parse_dict(const char *path, t_dict *out)
27–30: Locals: buf (file contents), count (pair count),
rc (result code from line parser).
32: init_out(out); safe baseline.
33–35: buf = slurp(path); if failed, return 1 (I/O error).
36–41: count = pass1_count_pairs(buf); if <= 0, free(buf)
and return 1 (invalid/empty dict).
42–47: Allocate out->pairs = malloc(sizeof(t_pair) * count);
on failure free(buf) and return 1.
48: out->size = count (temporary capacity;
final size will be corrected by parse_lines_into_pairs).
49: rc = parse_lines_into_pairs(buf, out);
50: free(buf); buffer no longer needed after duplication.
51–52: If rc != 0, free_dict(out) to avoid leaks; else sort_pairs(out) to keep deterministic order.
53: return rc (0 on success).

Why init_out + free_dict: centralizes ownership and avoids leaks on partial failures.

==============================
DICTIONARY HOUSEKEEPING

src/dict_sort.c — keep pairs ordered
What you’ll find and how each step maps to lines:
1: #include “rush02.h”
3–9: static int cmp_pair(const t_pair *a, const t_pair *b)
• Compare by numeric key as strings (ft_strlen first, then ft_strcmp)
if you want numeric ordering by magnitude; or plain ft_strcmp for lexicographic.
11–25: void sort_pairs(t_dict *d)
• Simple insertion sort or bubble sort to satisfy ≤25 lines
and no for/ternary (while/if only).
• Swaps entries in place based on cmp_pair().

Rationale: Sorted dictionary stabilizes lookups and makes optional binary search possible.

src/dict_lookup.c — get the word for a numeric key
Structure and mapping:
1: #include “rush02.h”
3–23: const char *dict_find(const t_dict *d, const char *key)
• Linear scan (idx from 0 to d->size-1) comparing ft_strcmp(d->pairs[i].key, key) == 0.
• Return d->pairs[i].val on match, else NULL at end.
Note: With sorted pairs, you may implement binary search (still ≤25 lines) if desired later.

src/free_all.c — free owned memory
Structure and mapping:
1: #include “rush02.h”
3–21: void free_dict(t_dict *d)
• If d == NULL return.
• Loop i = 0..d->size-1: free(d->pairs[i].key) and free(d->pairs[i].val) when non-NULL.
• free(d->pairs) and set to NULL; set d->size = 0.
Why: parse_dict duplicates every string; this central free keeps ownership clear.

==============================
CONVERSION PIPELINE

src/convert_io.c — spacing and output primitives
What’s in here:
1: #include “rush02.h”
3–14: int write_word(const char *s)
• Writes the string using write(1, …) in a small loop; returns 0 on success or non-zero on short write.
16–30: int write_space_if_needed(int *need_space)
• If *need_space is non-zero, write a single space and keep it set.
• If zero, set it to 1 (so future words will be preceded by a space).
• Return 0 on success; non-zero if write failed.

src/convert_two.c — 0..99
What’s in here and how it flows:
1: #include “rush02.h”
3–11: static int say_0_19(const t_dict *d, int n, int *need_space)
• Look up dict_find(d, “0”…“19”) and print via write_space_if_needed + write_word.
13–29: static int say_tens(const t_dict *d, int n, int *need_space)
• For 20,30,…,90: dict_find(d, “20”, “30”, …) and print.
31–62: int spell_two(const t_dict *d, int n, int *need_space)
• if (n < 20) return say_0_19.
• tens = (n / 10) * 10; ones = n % 10.
• print the tens word; if ones != 0, print a space and then the ones via say_0_19.
• Return 0 or error if a required key is missing in the dictionary.

Design note: We purposely avoid ternaries and hyphenation to keep Norme simple; hyphenation can be moved into the dictionary values if desired.

src/convert_hundreds.c — 100..999
Flow (map to your lines):
1: #include “rush02.h”
3–30: int spell_hundreds(const t_dict *d, int n, int *need_space)
• hundreds = n / 100; rest = n % 100.
• If hundreds > 0: say_0_19(d, hundreds), then print dict_find(d, “100”) (usually “hundred”).
• If rest > 0: call spell_two(d, rest, need_space).
• Return errors if any dict_find fails.

src/convert_scale.c — scales 10^3 and above
What you’ll see:
1: #include “rush02.h”
3–18: const char *scale_for_group(int g)
• g=0→NULL (no scale), 1→”1000”, 2→”1000000”, 3→”1000000000”, etc.
20–45: int spell_chunk_with_scale(const t_dict *d, int chunk, const char *scale, int *need_space)
• If chunk == 0: return 0 (nothing to print).
• spell_hundreds(d, chunk, need_space).
• If scale != NULL: write_space_if_needed + write_word(dict_find(d, scale)).

src/convert_main.c — orchestrator
How it runs:
1: #include “rush02.h”
3–11: static int split_into_groups(const char *digits, int groups[], int *ng)
• Walk digits from right to left, pack groups of 3 into int array: least significant group at index 0.
• Set *ng to number of groups.
13–43: int print_words(const t_dict *d, const char *digits)
• If digits equals “0”, just print dict_find(d, “0”).
• Call split_into_groups to fill groups[0..ng-1].
• need_space = 0.
• For g = ng-1 down to 0:
– If groups[g] != 0:
· scale = scale_for_group(g).
· spell_chunk_with_scale(d, groups[g], scale, &need_space).
• Return 0 or propagate errors if any word is missing in dict.

src/main.c — CLI, load, validate, convert, free
What’s inside, line mapping:
1: #include “rush02.h”
3–17: static int run_with_dict(const char *num, const char *dict_path)
• t_dict d; if (parse_dict(dict_path, &d) != 0) return non-zero.
• if (validate_num(num) != 0) { free_dict(&d); return non-zero; }
• if (print_words(&d, num) != 0) { free_dict(&d); return non-zero; }
• write(1, “\n”, 1); free_dict(&d); return 0.
19–47: int main(int argc, char **argv)
• If argc == 2: dict_path = “dicts/numbers.dict”;
num = argv[1]; return run_with_dict(num, dict_path).
• If argc == 3: dict_path = argv[1]; num = argv[2];
return run_with_dict(num, dict_path).
• Else: write usage or return error status per your school’s spec.

Why newline at end: most 42 graders expect a trailing newline for clean output.

==============================
WHY THIS 3-WAY SPLIT FOR CONVERSION

Two-digit rules (0–19 special names, tens like 20/30/…)
are different from hundreds, which are different again
from large scales (thousand/million/…). Splitting into
spell_two, spell_hundreds, and spell_chunk_with_scale
mirrors the structure of English numbers, keeps each
function ≤25 lines, and makes the main loop in
print_words trivial and readable.

==============================
HOW PARSING WORKS (DEEPER DETAIL)

slurp reads the entire file into memory (single contiguous buffer). 
pass1_count_pairs scans only for lines containing a colon to size
the pairs array exactly. parse_lines_into_pairs walks the buffer once,
turning each newline into ‘\0’ so each line becomes a C string in place.
Each line is split at the first colon, both sides are trim_spaces’d,
validated (non-empty), duplicated into freshly malloc’d strings,
and appended to out->pairs. After successful parsing, sort_pairs
orders entries so dict_find can be simple and deterministic. 
On any failure, parse_dict frees everything it allocated before
returning a non-zero error code.

==============================
WHY A CUSTOM DICTIONARY

The exercise requires data-driven wording. It lets you switch dialects (US vs UK “and”),
hyphenation, or even language by swapping only the dict file. It also makes testing 
trivial (inject minimal dicts or edge-case term sets) and decouples wording choices
from code so your C remains clean and Norme-compliant.

==============================
OPERATOR’S MANUAL (SEPARATE FROM THE README ABOVE)

Build
	1.	From the project root, run: make re

Run
	1.	Default dictionary:
./rush-02 12345
Loads dicts/numbers.dict and prints the words for 12345.
	2.	Custom dictionary:
./rush-02 path/to/custom.dict 7000001
Uses your custom wording.

Dictionary format
• One mapping per line: <word…>
Examples:
0: zero
1: one
10: ten
11: eleven
20: twenty
100: hundred
1000: thousand
1000000: million
• Leading/trailing spaces around key/value are allowed; trim_spaces removes them.
• Lines without a colon or with empty key/value are ignored.
• Keys must be digits only for reliable lookups.

Inputs and validation
• A “number” is a non-empty string of digits
(optionally you may allow one leading ‘+’,
depending on your validate_num).
• “0” is a special case: prints dictionary value for key “0”.
• For very large numbers, make sure your
scale_for_group supports enough groups (extend if needed).

Typical errors and resolutions
• “parse_dict failed” (non-zero return): Check file exists,
readable, and contains lines with colon and non-empty sides.
• “validate_num failed”: Make sure input is only digits and not empty.
• “missing word during conversion”: Ensure your dictionary
contains all the keys the converter needs:
0..19, 20,30,…,90, 100, plus 1000, 1000000, 1000000000,
…up to your target range.

Extending behavior
• British “and”: in spell_hundreds, when rest > 0,
insert the dictionary value for “and” between “hundred”
and the remainder (keep this optional to remain spec-compatible).
• Hyphenation: either bake hyphens directly in the dictionary
(e.g., “twenty-one”), or add a conditional in spell_two to
print “twenty-one” instead of “twenty one”.
• Larger scales: add new scale keys in the dict and extend
scale_for_group to return those keys.

Testing checklist
• 0, 1..19, 20, 21, 99
• 100, 101, 110, 115, 342, 900
• 1,000; 10,005; 105,000; 1,234,567
• Very large multi-group numbers to confirm scale sequencing
• Dictionary robustness: extra spaces, empty lines, missing trailing newline, etc.

Memory and cleanup
• On any parse failure, parse_dict frees partially built structures.
• On success, main must call free_dict(&d) before exiting.
• Keep functions within 25 lines and avoid forbidden constructs
(ternary, for); declare variables at top of scope; keep lines ≤80 chars; indent with tabs.

If you want, I can also generate a concise “cheat sheet” for
required dictionary keys (minimal set vs. full set to N groups),
or produce an annotated example conversion trace (from input digits
to each write_word call) for your QA notes.

⸻

Summary
	•	Modular, memory-safe design
	•	Uses custom dictionary input
	•	Three conversion layers for clarity and simplicity
	•	Norminette-compliant structure
	•	Easily extendable to new languages and larger scales

Author: Jaro

⸻
