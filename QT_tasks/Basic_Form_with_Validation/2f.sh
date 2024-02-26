#!/bin/bash

# find . searches for files and directories starting from the current directory
# -type f Specifies that the search should only include regular files (not directories or other types)
# -name '*.log': Filters the search to files with names ending in .log
# -print: Prints the result of the find command (the path of the found file) to the standard output.
# -quit: Tells find to stop searching after the first match is found. 

log_file=$(find . -maxdepth 1 -type f -name '*.log' -print -quit)


# -z  check if a string is empty
if [ -z "$log_file" ]; then
    echo "Error: No file with .log extension found."
    exit 1
fi

echo "Using log file: $log_file"

suppression_file="result.supp"

awk '/^{/,/^}$/' $log_file > $suppression_file

echo "Suppression rules added to $suppression_file"