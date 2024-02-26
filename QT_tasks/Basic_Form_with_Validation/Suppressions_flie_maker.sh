#!/bin/bash

read -p "Enter the Valgrind log file name: " log_file

if [ ! -f "$log_file" ]; then
    echo "Error: Log file '$log_file' not found."
    exit 1
fi

read -p "Enter the suppression file name: " suppression_file

awk '/^{/,/^}$/' $log_file >> $suppression_file

echo "Suppression rules added to $suppression_file"
