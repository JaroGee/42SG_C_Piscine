#!/bin/bash

# 1st test vars
# export FT_NBR1=\\\'\?\"\\\"\'\\
# export FT_NBR2='rcrdmddd'

# 2nd test vars
# export FT_NBR1=\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"
# export FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo

# "\"?!" base: base5 with digits: \=0, '=1, "=2, ?=3, !=4 (ordered)
# "mrdoc" base: base5 with digits: m=0, r=1, d=2, o=3, c=4
# gtaio luSnemf base: output base digits are the letters in the string (13 incl space)

NUM1=$(echo "$FT_NBR1" | tr \'\\\\\"\?\! '01234')
NUM2=$(echo "$FT_NBR2" | tr mrdoc '01234')
SUM=$(echo "obase=13; ibase=5; $NUM1 + $NUM2" | bc)

echo $SUM | tr '[:upper:]' '[:lower:]' | tr '0123456789abc' 'gtaio luSnemf'
