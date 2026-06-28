# Compiles a sketch for the Mega 2560 (no upload).
# Usage:  .\scripts\build.ps1 01_Blink
param([Parameter(Mandatory = $true)][string]$Name)
. "$PSScriptRoot\_common.ps1"
$dir = Join-Path "$Root\sketches" $Name
arduino-cli compile --fqbn $FQBN $dir
