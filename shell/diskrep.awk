BEGIN {print "*** WARNING ***"}
/\<[6-9][0-9]%/ {print "Partition "$6"\t: "$5" is almost full!"}
END {print "*** Give money for new disks URGENTLY! ***"}

