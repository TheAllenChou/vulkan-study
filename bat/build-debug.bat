@echo off
cd ..

"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/vulkan-study.sln" /build "Debug"

cd bat
@echo on
