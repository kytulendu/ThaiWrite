@echo off
echo.
echo Cleaning printer ...
del *.log
cd scup
del *.obj
cd ..
cd ..
del twprint.exe
cd src
echo Finish!
echo.
