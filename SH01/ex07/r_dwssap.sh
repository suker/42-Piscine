#!/bin/bash
cat /etc/passwd | grep -v '^#' | awk 'NR > 1' | awk 'NR%2' | egrep -o '([_a-z])+:\*'| sed 's/\:\*//g' | rev | sort -r | awk 'NR >= '$FT_LINE1' && 'NR' <= '$FT_LINE2'' | tr '\n' ',' | sed 's/,$/./' | tr -d '\n' | sed 's/,/, /g'
