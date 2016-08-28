@echo off
cd ..

"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/vulkan-study.sln" /rebuild "Release"

cd bat
@echo on
