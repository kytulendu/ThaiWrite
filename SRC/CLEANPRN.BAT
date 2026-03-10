@echo off
echo.
echo Cleaning printer ...
del *.log
cd scup
del *.obj
cd ..
cd ..
del cuprint.exe
cd src
echo Finish!
echo.
