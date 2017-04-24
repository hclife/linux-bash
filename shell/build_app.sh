#!/bin/bash
cd ../../android

source build/envsetup.sh > /dev/null

make $1 showcommands 2>&1 | tee ../oem/log/build_app.log
cd ../oem/scripts
