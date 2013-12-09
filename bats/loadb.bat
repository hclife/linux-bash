@echo off
echo This is for dubai mobile loading and doskey.
title adb                                       
E:
cd DB_Load\evts
prompt [$T]$C$P$F$G$S
echo Download and assign doskeys. 
doskey kmsg = adb shell cat /proc/kmsg
doskey logcat = adb logcat -v time
doskey dmesg = adb shell dmesg 
doskey sdmsg = adb shell dmesg > boot.msg
doskey sensord = adb logcat -s sensord
doskey Sensors = adb logcat -v time -s Sensors
doskey FTD = adb logcat -v time -s FTD 
doskey HAL = adb logcat -v time -s HAL 
doskey MMI = adb logcat -v time -s MMI
doskey OTP  = adb logcat -v time -s OTP
doskey PhoneApp = adb logcat -v time -s PhoneApp
doskey ActivityManager = adb logcat -v time -s ActivityManager
doskey reboot = adb shell reboot bootloader
doskey boot = fastboot flash boot boot.img
doskey system = fastboot flash system system.img.ext4
echo Preparation already ok.
adb shell
@echo on
