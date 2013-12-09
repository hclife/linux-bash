@echo off
echo This is for mobile loading and doskey.
d:
cd adb\fastboot\load\cairo
echo This window is to download and assign doskey. 
@echo on
doskey kmsg = adb shell cat /proc/kmsg
doskey logcat = adb logcat -v time
doskey dmesg = adb shell dmesg 
doskey sensord = adb logcat -s sensord
doskey Sensors = adb logcat -v time -s Sensors
doskey FTD = adb logcat -s FTD 
doskey HAL = adb logcat -s HAL 
doskey reboot = adb shell reboot bootloader
doskey devices = fastboot devices
doskey boot = fastboot flash boot boot.img
doskey system = fastboot flash system system.img.ext4
@echo Preparation already ok. 

title kmsg
@echo This window is to show kmsg
adb shell cat /proc/kmsg