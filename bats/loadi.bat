@echo off
echo This is for mobile loading and doskey.
title ics
d:
cd adb\fastboot\load\ics
echo This window is to download and assign doskey. 
doskey kmsg = adb shell cat /proc/kmsg
doskey logcat = adb logcat -v time
doskey dmesg = adb shell dmesg 
doskey sensord = adb logcat -s sensord
doskey Sensors = adb logcat -s Sensors
doskey FTD = adb logcat -s FTD 
doskey HAL = adb logcat -s HAL 
doskey PhoneApp = adb logcat -v time -s PhoneApp
doskey reboot = adb shell reboot bootloader
doskey boot = fastboot flash boot boot.img
doskey system = fastboot flash boot system.img.ext4
echo Preparation already ok. 
@echo on
