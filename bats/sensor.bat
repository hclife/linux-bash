@echo off
echo Install android sensors apk start.
adb devices
adb install "%userprofile%\Application Data\Wandoujia2\Download\Apps\sensor\system_info.apk"
adb install "%userprofile%\Application Data\Wandoujia2\Download\Apps\sensor\android_sensor.apk"
adb install "%userprofile%\Application Data\Wandoujia2\Download\Apps\sensor\SensorList_v2.1.apk"
adb install "%userprofile%\Application Data\Wandoujia2\Download\Apps\sensor\SensorMonitor.apk"
adb install "%userprofile%\Application Data\Wandoujia2\Download\Apps\sensor\supercompass.apk"
adb install "%userprofile%\Application Data\Wandoujia2\Download\Apps\sensor\Large_compass.apk"
echo Install android sensors apk finished.
@echo on