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
call rmdir /s /q build
popd

if /i "%~1" neq "nopause" pause
