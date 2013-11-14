#!/bin/bash
# program:
# use function to repeat information.
# history:
#     2011/06/09 Larkin Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

function printit(){
	echo -n "Your choice is $1"
}

echo "This program will print out your selection!"
case $1 in
  "one")
	printit 1
	;;
  "two")
	printit 2
	;;
  "three")
	printit 3
	;;
*)
	echo "Usage $0 should be {one|two|three}"
	exit 1
	;;
esac 
