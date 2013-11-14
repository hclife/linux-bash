#!/bin/bash
# program:
#	user input a number i
#	we calculate 1+2+...+i
# history:
#     2011/06/09 Larkin Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

read -p "Please input a number for calculation:" i
t=0
s=0
until [ "$t" == "$i" ]
do
	t=$(($t+1))
	s=$(($s+$t))
done
echo "The result of 1+2+...+$i is ==> $s"
