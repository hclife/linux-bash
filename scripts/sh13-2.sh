#!/bin/bash
# program:
#	repeat question until user input correct answer.
# history:
#     2011/06/09 Larkin Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

until [ "$yn" == "yes" -o "$yn" == "YES" ]
do
	read -p "Please input yes or YES to terminate." yn
done
echo "OK, you have input correct answer."

