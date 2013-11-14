#!/bin/bash
# program:
#	Try to calculate 1+2+...+${Input}
# history:
#	2011/06/15	Larkin	First Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

read -p "Input a number for accumulation " nu
s=0
for((i=1;i<=$nu;i=i+1))
do 
	s=$(($s+$i))
done
echo "The result of '1+2+...+$nu' is ==> $s"
