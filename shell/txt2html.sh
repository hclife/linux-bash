#!/bin/bash
echo "converting $1..."
SCRIPT="/home/larkin/scripts/scripts.sed"
NAME="$1"
TEMPFILE="/var/tmp/sed.$PID.tmp"
sed "s/\n/^M/" $1 | sed -f $SCRIPT | sed "s/^M/\n/" > $TEMPFILE
cp $TEMPFILE .
mv $TEMPFILE $NAME
echo "done."
