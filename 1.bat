@echo off
:: ǿ�ƹر� Chrome �����
echo ���ڹر� Chrome �����...
taskkill /im chrome.exe /f >nul 2>&1


if "%ProgramFiles(x86)%"=="" (
    set CHROME_PATH=%LOCALAPPDATA%\Google\Chrome\User Data
) else (
    set CHROME_PATH=%LOCALAPPDATA%\Google\Chrome\User Data
)


if exist "%CHROME_PATH%\Default\Cache" (
    echo �������� Chrome Ĭ���û��Ļ���...
    rd /s /q "%CHROME_PATH%\Default\Cache"
    echo Ĭ���û��Ļ���������ɡ�
) else (
    echo δ�ҵ�Ĭ���û��Ļ����ļ��С�
)


for /d %%i in ("%CHROME_PATH%\Profile*") do (
    echo �������� %%i �Ļ���...
    rd /s /q "%%i\Cache"
    echo %%i �Ļ���������ɡ�
)

echo ���� Chrome ����������ɣ�


echo ������������ Chrome �����...
start chrome


echo ������ɣ�Chrome ������������
pause
exit
