@echo off
echo This is for dubai mobile loading and doskey.
title mtk
I:
cd DB_Load\mtks
prompt [$T]$C$P$F$G$S
echo Download and assign doskeys. 
doskey ls = dir /q
doskey clear = cls
doskey cat = type
doskey .. = cd ..
doskey ... = cd ../../
doskey .... = cd ../../../
doskey as = adb shell
doskey ad = adb devices
doskey ar = adb reboot
doskey arf = adb reboot ftd
doskey arc = adb reboot charge
doskey arb = adb reboot bootloader
doskey aks = adb kill-server
doskey am = adb remount
doskey fd = fastboot devices
doskey fr = fastboot reboot

doskey kmsg = adb shell cat /proc/kmsg
doskey logcat = adb logcat -v time
doskey dmesg = adb shell dmesg 
doskey sdm = adb shell dmesg > boot.msg
doskey sum = adb logcat -v time -d > user.msg
doskey sdsm = adb shell dumpstate > dump.msg
doskey sensord = adb logcat -s sensord
doskey Sensors = adb logcat -v time -s Sensors
doskey SS = adb logcat -v time -s SensorService
doskey SM = adb logcat -v time -s SensorManager
doskey FTD = adb logcat -v time -s FTD 
doskey HAL = adb logcat -v time -s HAL 
doskey MMI = adb logcat -v time -s MMI
doskey OTP  = adb logcat -v time -s OTP
doskey PMS = adb logcat -v time -s PowerManagerService
doskey Printk = adb logcat -s PrintK
doskey PhoneApp = adb logcat -v time -s PhoneApp
doskey ActivityManager = adb logcat -v time -s ActivityManager
doskey reboot = adb shell reboot bootloader
doskey boot = fastboot flash boot boot.img
doskey system = fastboot flash system system.img.ext4
echo Preparation already ok. 
@echo on
