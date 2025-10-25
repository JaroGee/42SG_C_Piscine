RUSH 02 — Number to Words Converter (C Piscine Project)

Project Purpose

Rush 02’s goal is to create a C program that reads a dictionary file (numbers.dict) and converts a numeric string into its corresponding English words.

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

⸻

Summary
	•	Modular, memory-safe design
	•	Uses custom dictionary input
	•	Three conversion layers for clarity and simplicity
	•	Norminette-compliant structure
	•	Easily extendable to new languages and larger scales

Author: Jaro

⸻
