@echo off
chcp 65001 >nul

REM FeatherArch Build Script for Windows CMD
REM Usage: build.bat <target> <cc> <ar> <cflags> [build_dir]
REM
REM Example:
REM   build.bat cm4 clang llvm-ar "--target=arm-none-eabi -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -O3 -std=c11 -Wall" build

if "%~4"=="" (
    echo Usage: build.bat ^<target^> ^<cc^> ^<ar^> ^<cflags^> [build_dir]
    echo.
    echo Targets: cm4, cm7, cm33, cm55, cm85
    echo.
    echo Example:
    echo   build.bat cm4 clang llvm-ar "--target=arm-none-eabi -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -O3 -std=c11 -Wall" build
    exit /b 1
)

set "TARGET=%~1"
set "CC=%~2"
set "AR=%~3"
set "CFLAGS=%~4"
set "BUILD_DIR=%~5"

if "%BUILD_DIR%"=="" set "BUILD_DIR=build"

echo ==========================================
echo Building FeatherArch for target: %TARGET%
echo CC: %CC%
echo AR: %AR%
echo CFLAGS: %CFLAGS%
echo BUILD_DIR: %BUILD_DIR%
echo ==========================================
echo.

REM Create build directory
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

REM Create temporary ninja file with substituted variables using PowerShell
powershell -Command "$content = Get-Content -Raw -Path 'build.ninja'; $content = $content -replace '\\$ENV\\{TARGET\\}', '%TARGET%'; $content = $content -replace '\\$ENV\\{CC\\}', '%CC%'; $content = $content -replace '\\$ENV\\{AR\\}', '%AR%'; $content = $content -replace '\\$ENV\\{CFLAGS\\}', '%CFLAGS%'; $content = $content -replace '\\$ENV\\{BUILD_DIR\\}', '%BUILD_DIR%'; $content = $content -replace '\\$ENV\\{INCLUDES\\}', ''; Set-Content -Path '%BUILD_DIR%\build_%TARGET%.ninja' -Value $content"

REM Run ninja
ninja -f "%BUILD_DIR%\build_%TARGET%.ninja" %TARGET%

if %errorlevel% neq 0 (
    echo.
    echo Build failed!
    exit /b 1
)

echo.
echo ==========================================
echo Build successful!
echo Output: %BUILD_DIR%\libfeatherarch_%TARGET%.a
echo ==========================================
