#!/bin/bash
# Program:
#	User inputs a filename, the program checks as followed:
#	1. exist?  2. file or directory?  3. file permission
# History:
2011/05/21	Larkin	First release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

#1. Make the user input file name, 
#  and judge that if user has really input string?
echo -e "Please input a filename, I will check the filename's type and \
permissions."
read -p "Input a filename: " filename
test -z $filename && echo "You MUST input a filename." && exit 0
#2. Check out if the file exist or not?
#   If not, then print message and end script
test ! -e $filename && echo "The file '$filename' DONOT exit!" && exit 0
#3. Start to determine file type and attribute
test -f $filename && filetype="Regular File"
test -d $filename && filetype="directory"
test -r $filename && perm="readable"
test -w $filename && perm="$perm writable"
test -x $filename && perm="$perm executable"
#4. Output the information.
echo "The filename: $filename is a $filetype"
echo "And the permissions are : $perm"
