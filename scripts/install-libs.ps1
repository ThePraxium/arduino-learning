# Installs the libraries needed for these projects.
# Safe to re-run; already-installed libraries are skipped.
# Usage:  .\scripts\install-libs.ps1
. "$PSScriptRoot\_common.ps1"

$libs = @(
    "DHT sensor library",        # DHT11 temp/humidity
    "Adafruit Unified Sensor",   # dependency for DHT + ADXL345
    "IRremote",                  # IR receiver + remote
    "RTClib",                    # DS3231 real-time clock
    "MFRC522",                   # RC522 RFID reader
    "Adafruit ADXL345"           # ADXL345 accelerometer
)
# Note: LiquidCrystal, Servo, and Stepper ship with the AVR core already.

foreach ($lib in $libs) {
    Write-Host "Installing '$lib' ..." -ForegroundColor Cyan
    arduino-cli lib install $lib
}
Write-Host "Done. Run 'arduino-cli lib list' to see everything installed." -ForegroundColor Green
