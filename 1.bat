# ????????????
if (-not ([Security.Principal.WindowsPrincipal] 
[Security.Principal.WindowsIdentity]::GetCurrent())
.IsInRole([Security.Principal.WindowsBuiltInRole]
 "Administrator")) {
    # ????????????
    $scriptPath = $MyInvocation.MyCommand.Path
    Start-Process powershell.exe
     -ArgumentList 
     "-NoProfile -ExecutionPolicy Bypass -File `
     "$scriptPath`"" -Verb RunAs
    exit
}

# ??????????WPS Office???
$wpsProduct = Get-WmiObject -Class Win32_Product 
| Where-Object { $_.Name -match "WPS Office" }

if ($wpsProduct) {
    Write-Output "WPS Office ????????..."
    $wpsProduct.Uninstall() 
    | Out-Null

    $wpsProduct = Get-WmiObject -Class Win32_Product 
    | Where-Object { $_.Name -match "WPS Office" }
    if (-not $wpsProduct) {
        Write-Output "WPS Office ??????"
    } else {
        Write-Output "???????????"
    }
} else {
    Write-Output "???????WPS Office?"
}
