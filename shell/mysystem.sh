#!/bin/bash
clear
echo "This is the information provided by mysystem.sh. Program starts."

echo "Hello $USER"
echo

echo "Today is `date`, this week is `date +"%V"`."
echo

echo "These users are currently connected:"
w | cut -d " " -f 1 - | grep -v USER | sort -u
echo

echo "This is `uname -s` running on a `uname -m` processor."
echo

echo "This is the uptime information:"
uptime
echo

echo "I will now fetch you a list of connected users:"
w

echo "I'm setting variables now."
COLOR="black"
VALUE="9"
WEATHER="sunshine"
echo "The string $COLOR and number $VALUE and weather is $WEATHER"
echo

echo "That's all folks!"
