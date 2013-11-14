#!/bin/bash
# program:
# use function to repeat information.
# history:
#     2011/06/09 Larkin Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

function printit(){
	echo -n "Your choice is "
}

echo "This program will print out your selection!"
case $1 in
  "one")
	printit; echo $1 | tr 'a-z' 'A-Z'
	;;
  "two")
	printit; echo $1 | tr 'a-z' 'A-Z'
	;;
  "three")
	printit; echo $1 | tr 'a-z' 'A-Z'
	;;
*)
	echo "Usage $0 should be {one|two|three}"
	exit 1
	;;
esac 
