#!/bin/bash

id -Gn $FT_USER | tr ' ' ',' | tr -d '\n'

# id -Gn $FT_USER: Prints all the groups that $FT_USER belongs to, sperated by spaces
# tr ' ' ',': Replaces all spaces with comas
# tr -d '\n': Removes the new line
