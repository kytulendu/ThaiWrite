@echo off
echo. >> log.log
echo =============================================================================== >> log.log
echo. >> log.log
cd ..
del *.exe
cd src
cd common
echo Building common library.
make >> ..\log.log
echo Done!
cd ..
cd scuw
cd thaisep
echo Building Thai word separation library.
make >> ..\..\log.log
echo Done!
cd..
echo Building editor.
make >> ..\log.log
echo Done!
cd ..
cd scup
echo Building printer.
make >> ..\log.log
echo Done!
cd ..
cd scuf
echo Building font editor.
make >> ..\log.log
echo Done!
cd ..
