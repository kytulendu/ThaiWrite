@echo off
cd ..
del twfont.exe
cd src
cd scuf
echo Building font editor.
make
echo Done!
cd ..
