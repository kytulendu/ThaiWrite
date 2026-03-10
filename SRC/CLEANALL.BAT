@echo off
echo.
echo Cleaning project ...
del *.log
cd common
del *.obj
del *.err
cd ..
cd scuw
del *.obj
rem cd thaisyls
rem del *.obj
rem cd ..
cd ..
cd scup
del *.obj
cd ..
cd scuf
del *.obj
cd ..
cd ..
del *.exe
cd src
echo Finish!
echo.
