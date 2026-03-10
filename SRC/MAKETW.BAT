@echo off
cd ..
del cw.exe
cd src
cd scuw
rem cd thaisep
rem echo Building Thai word separation library.
rem make
rem echo Done!
rem cd..
echo Building editor.
make
echo Done!
cd ..
