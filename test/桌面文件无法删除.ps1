#权限
if (-not ([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) {

    Start-Process powershell.exe "-NoProfile -ExecutionPolicy Bypass -File `"$PSCommandPath`"" -Verb RunAs
    Exit
}
#关闭应用
Get-Process | Where-Object { $_.MainWindowTitle -ne "" } | Stop-Process -Force
#执行命令
Remove-Item -Path $env:temp"\" -Recurse -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5

