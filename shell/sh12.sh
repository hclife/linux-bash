#!/bin/bash
# program:
# this script only accepts the flowing parameters: one, two or three.
# history:
#     2011/06/09 Larkin Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

echo "This program will print out your selection!"
read -p "Input now:" choice
case $choice in
#case $1 in
  "one")
	echo "Your choice is ONE"
	;;
  "two")
	echo "Your choice is TWO"
	;;
  "three")
	echo "Your choice is THREE"
	;;
*)
	echo "Usage $0 should be {one|two|three}"
	exit 1
	;;
esac 
