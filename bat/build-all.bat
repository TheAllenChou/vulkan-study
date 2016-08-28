@echo off
cd ..

"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/vulkan-study.sln" /build "Debug"
"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/vulkan-study.sln" /build "Release"
"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/vulkan-study.sln" /build "Ship"

cd bat
@echo on
