@echo off
chcp 65001 > nul
setlocal enabledelayedexpansion

cd /d "%~dp0..\.."

set "TARGET_DIR=resources\.user_build"

echo [BUILD] Enter user build creation in folder : resources\.user_build..

if exist "%TARGET_DIR%" (
    echo [BUILD] Removing old build..
    rmdir /s /q "%TARGET_DIR%"
)
mkdir "%TARGET_DIR%"

echo [BUILD] Copying bprint and include..
if exist "bprint"  xcopy "bprint" "%TARGET_DIR%\bprint\" /E /I /Y /Q > nul
if exist "include" xcopy "include" "%TARGET_DIR%\include\" /E /I /Y /Q > nul

echo [BUILD] Enter resources folder copy..
robocopy "resources" "%TARGET_DIR%\resources" /E /XD ".user_build" > nul

echo [BUILD] Enter DLib and BIN resource copy..
copy /Y "*.exe" "%TARGET_DIR%\" > nul
copy /Y "*.dll" "%TARGET_DIR%\" > nul

echo [BUILD] Clening up (.lib)...
if exist "%TARGET_DIR%\*.lib" del /q "%TARGET_DIR%\*.lib"

echo --------------------------------------------------
echo [SUCCESS] Its all
echo %cd%\%TARGET_DIR%
echo --------------------------------------------------
pause
