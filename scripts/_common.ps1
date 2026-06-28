# Shared configuration sourced by every helper script in this folder.
# Edit the two values below if your setup ever changes.

$ArduinoCliDir = "C:\Program Files\Arduino CLI"
if (Test-Path $ArduinoCliDir) { $env:Path = "$ArduinoCliDir;$env:Path" }

# Board: Inland / Keyestudio Mega 2560 R3  ->  arduino:avr:mega (default cpu = atmega2560)
$script:FQBN = "arduino:avr:mega"
$script:BAUD = 9600

# Absolute path to the project root (one level up from this scripts/ folder)
$script:Root = (Resolve-Path "$PSScriptRoot\..").Path

function Get-BoardPort {
    # Returns the serial port address of the first connected board, or $null.
    # Handles both arduino-cli 1.x ({detected_ports:[...]}) and older array output.
    $raw = arduino-cli board list --format json | Out-String
    if (-not $raw.Trim()) { return $null }
    $data = $raw | ConvertFrom-Json
    $ports = if ($data.detected_ports) { $data.detected_ports } else { $data }
    foreach ($p in $ports) {
        if ($p.port.protocol -eq 'serial') { return $p.port.address }
    }
    return $null
}
