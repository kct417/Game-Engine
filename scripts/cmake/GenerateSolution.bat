@echo off

pushd %~dp0\..\..\
call cmake -G "Visual Studio 17 2022" -S . -B build
popd

if /i "%~1" neq "nopause" pause
