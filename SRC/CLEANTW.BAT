@echo off
echo.
echo Cleaning editor ...
del *.log
cd scuw
del *.obj
cd thaisep
del *.obj
cd ..
cd ..
cd ..
del tw.exe
cd src
echo Finish!
echo.
