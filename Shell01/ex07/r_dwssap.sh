#!/bin/bash
cat /etc/passwd \
 | grep -v '^#' \
 | sed -n 'n;p' \
 | cut -d ':' -f1 \
 | rev \
 | sort -r \
 | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" \
 | tr '\n' ',' \
 | sed 's/,/, /g' \
 | sed 's/, $/./'

# cat /etc/ passwd:  Reads system users
# grep -v '^#': Removes comment lines
# sed -n 'p;p' Keeps every 2nd line (start from 2nd)
# cut -d ':' -f1: Extracts login names only
# rev: Reverses each username
# sort -r:Sorts in reverse alphabetical order
# awk "NR>=$FT_LINE1 && NR<=$FT_LINE2": Keeps only lines in range
# tr '\n' ',': Joins all into one line separated by commas
# sed 's/,/, /g': Adds space after commas
# sed 's/, $/./': Replaces last commas with a period

