#!/bin/bash
# This script is to diff symbolics and plain files.
echo "Start processing..."
# save the object symlink format to bin1.txt
ls -l /usr/bin | sed '/^l/i\--This is a symlink--' > bin1.txt
# save the plain files to bin2.txt first
ls -l /usr/bin | sed '/^l/d' > bin2.txt
sed 's/$/<<--This is a plain file--/g' bin2.txt > bin3.txt
ls -l bin*.txt
