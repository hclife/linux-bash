#!/bin/bash
# Program:
# User inputs his first name and last name. Program shows his full name.
# History:
# 2011/05/21	Larkin	First Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
read -p "Please input your first name: " first_name
read -p "Please input your last name: " last_name
echo -e "Your full name is: $first_name $last_name"

