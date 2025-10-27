@echo off
call GenerateSolution.bat nopause
pushd %~dp0\..\..\
call msbuild
popd

if /i "%~1" neq "nopause" pause
