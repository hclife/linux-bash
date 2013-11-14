#!/bin/bash
read -p "Input birthday (MMDD, ex>0709):" bir
now=`date +%m%d`
if [ "$bir" == "$now" ]; then
	echo "Happy birthday to you!"
elif [ "$bir" -gt "$now" ]; then
	year=`date +%Y`
	total_d=$(($((`date --date="$year$bir" +%s`-`date +%s`))/60/60/24))
	echo "Your birthday will be $total_d days later"
else
	year=$((`date +%Y`+1))
	total_d=$(($((`date --date="$year$bir" +%s`-`date +%s`))/60/60/24))
	echo "Your birthday will be $total_d days later"
fi
