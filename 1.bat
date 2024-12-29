@echo off
:: 强制关闭 Chrome 浏览器
echo 正在关闭 Chrome 浏览器...
taskkill /im chrome.exe /f >nul 2>&1


if "%ProgramFiles(x86)%"=="" (
    set CHROME_PATH=%LOCALAPPDATA%\Google\Chrome\User Data
) else (
    set CHROME_PATH=%LOCALAPPDATA%\Google\Chrome\User Data
)


if exist "%CHROME_PATH%\Default\Cache" (
    echo 正在清理 Chrome 默认用户的缓存...
    rd /s /q "%CHROME_PATH%\Default\Cache"
    echo 默认用户的缓存清理完成。
) else (
    echo 未找到默认用户的缓存文件夹。
)


for /d %%i in ("%CHROME_PATH%\Profile*") do (
    echo 正在清理 %%i 的缓存...
    rd /s /q "%%i\Cache"
    echo %%i 的缓存清理完成。
)

echo 所有 Chrome 缓存清理完成！


echo 正在重新启动 Chrome 浏览器...
start chrome


echo 清理完成，Chrome 已重新启动。
pause
exit
