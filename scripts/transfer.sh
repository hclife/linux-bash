#!/bin/bash
# Program: Transfer img from amss to android. 
# History:
# 2012/04/19    Larkin  First Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
echo "orange evt3u lexus start transfer progress."
cp ./modem_proc/core/storage/tools/jsdcc/partition_load_pt/partition.bin  ../android/out/oret3uR_lex/target/product/orange
echo "partition.bin has been transferred."
cp ./modem_proc/build/ms/bin/ORANGEEVT3ULEXUSD_AAABQNBY/sbl1.mbn ../android/out/oret3uR_lex/target/product/orange
cp ./modem_proc/build/ms/bin/ORANGEEVT3ULEXUSD_AAABQNBY/sbl2.mbn ../android/out/oret3uR_lex/target/product/orange 
cp ./modem_proc/build/ms/bin/ORANGEEVT3ULEXUSD_AAABQNBY/sbl3.mbn ../android/out/oret3uR_lex/target/product/orange
echo "sbl1.2.3 has been transferred."
cp ./modem_proc/build/ms/bin/ORANGEEVT3ULEXUSD_AAABQNBY/rpm.mbn ../android/out/oret3uR_lex/target/product/orange
echo "rpm.mbn has been transferred."
cp ./modem_proc/build/ms/bin/ORANGEEVT3ULEXUSD_AAABQNBY/tz.mbn ../android/out/oret3uR_lex/target/product/orange
echo "tz.mbn has been transferred."
echo "Transporting progress is over. The whole images is under android folder."
