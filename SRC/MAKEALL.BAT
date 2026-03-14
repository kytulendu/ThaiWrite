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
cd thaisep
echo Building Thai word separation library.
make
echo Done!
cd..
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
