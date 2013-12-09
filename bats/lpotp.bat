@echo off
echo Erase lpsensor new otp area data. 
adb devices
adb shell otp_test -a 4 4
adb shell otp_test -a 2 LPSENSOR_CAL_DATA
adb reboot
echo erase finished and reboot machine.
@echo on