#!/bin/bash
if [ ! -e logical ]; then
	touch logical
	echo "Just make a logical file"
	exit 1
elif [ -e logical ] && [ -f logical ]; then
	rm logical
	mkdir logical
	echo "Remove file ==> logical"
	echo "And make directory logical"
	exit 1
elif [ -e logical ] && [ -d logical ]; then
	rm -rf logical
	echo "Remove directory ==> logical"
	exit 1
else 
	echo "Is here anything left?"
fi
