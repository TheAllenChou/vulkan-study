@echo off
cd ..

:: remove solutionn folder
echo Removing Visual Studio solution...
if exist solution rmdir /Q /S solution
echo Done.

cd bat
@echo on
