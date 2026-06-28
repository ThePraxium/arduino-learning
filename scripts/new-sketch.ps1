# Creates a new sketch folder under sketches/.
# Usage:  .\scripts\new-sketch.ps1 02_Button
param([Parameter(Mandatory = $true)][string]$Name)
. "$PSScriptRoot\_common.ps1"
$dir = Join-Path "$Root\sketches" $Name
if (Test-Path $dir) { Write-Host "Sketch '$Name' already exists at $dir" -ForegroundColor Yellow; return }
arduino-cli sketch new $dir
Write-Host "Created $dir" -ForegroundColor Green
