@echo off
cd ..
del cufont.exe
cd src
cd scuf
echo Building font editor.
make
echo Done!
cd ..
