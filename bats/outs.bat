@echo off
echo Cleaning the outlook temp files to release space.
del  /s /q "%userprofile%\Local Settings\Temporary Internet Files\*.*" 
echo The outlook temp files have been cleared successfully.
echo. & pause
@echo on
