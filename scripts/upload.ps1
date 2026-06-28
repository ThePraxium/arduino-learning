# Compiles and uploads a sketch to the Mega 2560.
# Usage:  .\scripts\upload.ps1 01_Blink
#         .\scripts\upload.ps1 01_Blink -Port COM5   (override auto-detect)
param(
    [Parameter(Mandatory = $true)][string]$Name,
    [string]$Port
)
. "$PSScriptRoot\_common.ps1"
$dir = Join-Path "$Root\sketches" $Name
if (-not $Port) { $Port = Get-BoardPort }
if (-not $Port) {
    Write-Host "No board detected. Plug in the Mega over USB, or pass -Port COMx." -ForegroundColor Red
    return
}
Write-Host "Uploading $Name to $Port ..." -ForegroundColor Cyan
arduino-cli compile --fqbn $FQBN $dir
if ($LASTEXITCODE -ne 0) { Write-Host "Compile failed - not uploading." -ForegroundColor Red; return }
arduino-cli upload --fqbn $FQBN -p $Port $dir
