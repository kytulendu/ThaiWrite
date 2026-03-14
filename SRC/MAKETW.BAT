@echo off
cd ..
del tw.exe
cd src
cd scuw
cd thaisep
echo Building Thai word separation library.
make
echo Done!
cd..
echo Building editor.
make
echo Done!
cd ..
