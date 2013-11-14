#!/bin/bash
# Program:
#	This program shows the effect of shift function.
# History:
# 2011/05/22	Larkin		First release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

echo "Total parameter number is  ==> $#"
echo "Your whole parameters are  ==> '$@'"
shift  # make the first shift: one variable
echo "Total parameter number is  ==> $#"
echo "Your whole parameters are  ==> '$@'"
shift 3 # make the second shift: three variables
echo "Total parameter number is  ==> $#"
echo "Your whole parameters are  ==> '$@'"
