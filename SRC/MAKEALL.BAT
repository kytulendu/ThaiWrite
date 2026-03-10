@echo off
cd ..
del *.exe
cd src
cd common
echo Building common library.
make
echo Done!
cd ..
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
cd scup
echo Building printer.
make
echo Done!
cd ..
cd scuf
echo Building font editor.
make
echo Done!
cd ..
