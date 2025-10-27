@echo off

set "ROOT=%~dp0\..\.."
pushd "%ROOT%" >nul
set "ROOT=%CD%"
popd >nul

@REM echo WARNING: This will delete build folders inside:
@REM echo %ROOT%
@REM echo.
@REM set /p userInput=Do you want to continue? (y/n): 
@REM if /i "%userInput%" NEQ "y" (
@REM     pause
@REM     goto :EOF
@REM )
@REM echo.

pushd "%ROOT%"
rmdir /s /q bin
rmdir /s /q build
del /s /q *.sln
del /s /q *.vcxproj
del /s /q *.vcxproj.filters
popd

if /i "%~1" neq "nopause" pause
