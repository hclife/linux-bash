#!/bin/bash
echo "please input a number:"
read var1
echo "please input a number:"
read var2

if [ "$var1" -ge "$var2" ];
then
	echo "var1 >= var2"
	exit 0
else 
	echo "var1 <= var2"
	exit 0
fi

