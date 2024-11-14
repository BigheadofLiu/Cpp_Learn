# 查询定位服务状态
$locationStatus = Get-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location" -Name "Value"

if ($locationStatus.Value -eq "Allow") {
    Write-Host "定位服务已启用。"
} else {
    Write-Host "定位服务未启用。"
}
