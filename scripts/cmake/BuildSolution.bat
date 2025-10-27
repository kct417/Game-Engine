@echo off
call GenerateSolution.bat nopause
pushd %~dp0\..\..\
call cmake --build build
popd

if /i "%~1" neq "nopause" pause
