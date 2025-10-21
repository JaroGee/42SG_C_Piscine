#!/bin/bash
ls -l | sed -n 'p;n'

# ls -l: Lists files with details
# |: Pipes (sends) the output to the next command
# sed: Edit the text flow to output
# -n: sed output is done according to the past standard; stops automatic printing
# 'p;n': p(prints the current line of the input) n(Skips the next line)
