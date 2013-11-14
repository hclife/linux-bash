#!/bin/bash
# Perform sed exercises of Chapter 5 of bash book.
echo "The file to be processed is here:"
ls -l web2
nl web2 | sed -n '1,3d' > cut.txt
sed -n '/an/p' web2 > an.txt
sed '/^.man..$/i***This might have something to do with man and man pages.***' web2 > ins.txt
echo "The file is processed over."
