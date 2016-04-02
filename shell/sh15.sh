#!/bin/bash
# program:
#	using for ... loop to print 3 animals
# history:
#     2011/06/09 Larkin Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

for animal in dog cat elephant
do 
	echo "These are "$animal"s..."
done
