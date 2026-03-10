@echo off
cd ..
del cuprint.exe
cd src
cd scup
echo Building printer.
make
echo Done!
cd ..
