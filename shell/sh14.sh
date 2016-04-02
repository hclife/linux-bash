#!/bin/bash
# program:
#	use loop to calculate "1+2+...+100".
# history:
#     2011/06/09 Larkin Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
 
s=0
i=0
while [ "$i" != "100" ]
do 
	i=$(($i+1))
	s=$(($s+$i))
	echo "now s=$s"
done
echo "The result of 1+2+...+100 is ==> $s"

