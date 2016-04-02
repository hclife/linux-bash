#!/bin/bash
# Program:
#	User input 2 integer nums, program cross them
# History:
# 2011/05/20	Larkin	First Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
echo -e "You SHOULD input 2 numbers, and I will cross them!\n"
read -p "First number: " first_nu
read -p "Second number: " second_nu
#total=$(($first_nu*$second_nu))
declare -i total=$first_nu*$second_nu
echo -e "\nThe result of $first_nu x $second_nu is ==> $total"
