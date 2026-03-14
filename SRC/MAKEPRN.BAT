@echo off
cd ..
del twprint.exe
cd src
cd scup
echo Building printer.
make
echo Done!
cd ..
