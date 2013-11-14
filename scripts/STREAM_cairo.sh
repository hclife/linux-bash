#!/bin/bash
# Program: Get Cairo Qplatform code. 
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
mkdir android
cd android
repo init -u git://10.82.164.21/Data/cairo/platform/manifest.git -b MSM8660_ICS 
repo sync
repo start MSM8660_ICS --all
cd ..
git clone git://10.82.164.21/Data/cairo/oem.git -b MSM8660_ICS
git clone git://10.82.164.21/Data/cairo/amss.git -b MSM8660_ICS
cd oem/cairo_scripts
./build_android.sh evt2u hermes release > android.log
echo "The MSM8660_ICS code fetching process is accomplished."

