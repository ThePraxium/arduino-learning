# Lists connected boards and their serial ports.
# Usage:  .\scripts\find-board.ps1
. "$PSScriptRoot\_common.ps1"
arduino-cli board list
