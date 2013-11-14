#!/bin/bash
# program:
#	show "Hello" from $1... by using case...esac
# history:
#     2011/06/08 Larkin Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

case $1 in
  "hello")
	echo "Hello, how are you?"
	;;
"")
	echo "You Shall input parameters man: ex> {$0 someword}"
	;;
*)
	echo "Usage $0 {hello}"
	;;
esac
