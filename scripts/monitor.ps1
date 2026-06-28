# Opens the serial monitor. Press Ctrl+C to exit.
# Usage:  .\scripts\monitor.ps1
#         .\scripts\monitor.ps1 -Baud 115200 -Port COM5
param(
    [string]$Port,
    [int]$Baud = 9600
)
. "$PSScriptRoot\_common.ps1"
if (-not $Port) { $Port = Get-BoardPort }
if (-not $Port) {
    Write-Host "No board detected. Plug in the Mega over USB, or pass -Port COMx." -ForegroundColor Red
    return
}
Write-Host "Monitoring $Port at $Baud baud (Ctrl+C to quit) ..." -ForegroundColor Cyan
arduino-cli monitor -p $Port --config baudrate=$Baud
