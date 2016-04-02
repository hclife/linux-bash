#!/bin/bash
# It prints a msg about your weight 
# if you give reset in kilos and hight in centimeters.

if [ $# != 2 ]; then
echo "usage: $0 weightinkilos lengthincentimerters."
exit
fi

weight="$1"
height="$2"
idealweight=$[$height -110]
if [ $weight -le $idealweight ]; then
echo "You should eat a bit more fat."
else 
echo "You should eat a bit more fruit."
fi

