wpeinit
@echo off
color 3f
rem set server=192.168.100.1
set server=WDS

:pingloop
ping %server% -n 1 >nul
if errorlevel 1 (
    echo wait for %server% server...
    REM timeout /t 5 >nul
    ping localhost -n 5 >nul
    goto :pingloop
) else (
    echo ---------------------------------------
    echo %server% server connected.
    echo ---------------------------------------
    echo try to mount network share...
    echo ---------------------------------------
    goto:netloop
)
:netloop
net use z: \\WDS\images 1 /user:WDS\ZYB
if %errorlevel% neq 0 (
    echo ---------------------------------------
    echo mount fail,try again...
    echo ---------------------------------------
    rem timeout /t 5
    ping localhost -n 5 >nul
    goto netloop
) else (
    cls
    echo ---------------------------------------
    echo mount success,begin to install system...
    echo ---------------------------------------
    z:\init.bat
)