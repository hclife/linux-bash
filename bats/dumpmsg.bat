@echo off
echo update the boot.msg for debug.
adb devices
echo 1. The old boot.msg is listed as below:
dir /q boot.msg
del boot.msg
adb shell dmesg > boot.msg
echo 2. The new boot.msg is listed as below:
dir /q boot.msg
echo update finished.
@echo on