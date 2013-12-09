@echo off
echo adb install useful apks to phones.
h:
cd H:\apks
dir /q /d *.apk
adb devices
adb install org.wikipedia_25.apk
adb install OfficeSuite.apk
adb install chinese.carExamC.apk
adb install kuaipaierweima.apk
adb install xingzuodashi.apk
adb install google_earth.apk
adb install FileExpert.apk
adb install wangyiyouxiang.apk
adb install baiduinput.apk
adb install QQ.apk
adb install github.apk
adb install baiduinstall.apk
adb install Bestlover.apk
adb install MX.videoplayer.apk
adb install souhuxinwen.apk
adb install WeChat.apk
adb install 58tongcheng_4400.apk
adb install sina.weibo.apk
adb install com.powermusic.maxmpz.audioplayer.apk
adb install Large_compass.apk
adb install meituan_movie.apk

echo install over.
@echo on