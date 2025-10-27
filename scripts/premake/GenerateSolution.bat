@echo off

pushd %~dp0\..\..\
call vendor\premake\bin\premake5 vs2022
popd

if /i "%~1" neq "nopause" pause

