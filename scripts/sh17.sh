#!/bin/bash
# program:
#	use ping cmd to check the network's PC state.
# history:
#     2011/06/09 Larkin Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

network="10.85.21"
for sitenu in $(seq 1 100)
do
# check the call back value to see if ping is successful or failed
	ping -c 1 -w 1 ${network}.${sitenu} &> /dev/null && result=0 || retult=1
	if [ "$result" == 0 ]; then
		echo "Server ${network}.${sitenu} is UP."
	else 
		echo "Server ${network}.${sitenu} is DOWN."
	fi
done
