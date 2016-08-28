@echo off
cd ..

"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/vulkan-study.sln" /build "Release"

cd bat
@echo on
