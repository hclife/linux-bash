@echo off
echo change root permission for device.
c:
cd c:\Python26
adb devices
python adb_enable2.py -root
call ping 1.1.1.1 -n 2 > nul
adb reboot
e:
cd DB_Load\evts
echo Now device has root permission.
@echo on
