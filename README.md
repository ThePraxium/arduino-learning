# Arduino Learning — Inland Super Starter Kit (Mega 2560 R3)

A command-line workspace for working through the Inland Super Starter Kit
(Micro Center SKU 052043) using **arduino-cli** — no Arduino IDE needed.

- **Board:** Inland / Keyestudio Mega 2560 R3
- **FQBN:** `arduino:avr:mega`
- **Toolchain:** arduino-cli (installed at `C:\Program Files\Arduino CLI`)

## Layout

```
Arduino_learning/
├─ sketches/        one folder per sketch (the arduino-cli convention)
│  └─ 01_Blink/01_Blink.ino
├─ learn/           interactive HTML lesson guides — open in a browser
│  ├─ 06_button_controlled_led.html   (one per kit Project; offline, self-contained)
│  └─ _kit/template.html              reusable guide template (portrait diagram engine)
├─ scripts/         PowerShell helpers (see below)
├─ libraries/       drop hand-installed / custom libraries here
├─ docs/
│  └─ components.md  full parts list + pinouts + library map
└─ README.md
```

## Daily workflow

Run these from the project root in PowerShell.

| Task | Command |
|------|---------|
| See which COM port the board is on | `.\scripts\find-board.ps1` |
| Create a new sketch | `.\scripts\new-sketch.ps1 02_Button` |
| Compile only (catch errors) | `.\scripts\build.ps1 01_Blink` |
| Compile **and** upload | `.\scripts\upload.ps1 01_Blink` |
| Open the serial monitor | `.\scripts\monitor.ps1` |
| Install this kit's libraries | `.\scripts\install-libs.ps1` |

The upload/monitor scripts auto-detect the board's COM port. If you have several
serial devices, pass it explicitly: `.\scripts\upload.ps1 01_Blink -Port COM5`.

### First time PowerShell blocks the scripts?

If you see an "execution policy" error, allow local scripts for your user once:

```powershell
Set-ExecutionPolicy -Scope CurrentUser RemoteSigned
```

## Raw arduino-cli (what the scripts wrap)

```powershell
arduino-cli board list                                  # find the port
arduino-cli compile --fqbn arduino:avr:mega sketches\01_Blink
arduino-cli upload  --fqbn arduino:avr:mega -p COM5 sketches\01_Blink
arduino-cli monitor -p COM5 --config baudrate=9600
arduino-cli lib search dht                               # find a library
arduino-cli lib install "DHT sensor library"
```

## Where things are installed

- arduino-cli binary: `C:\Program Files\Arduino CLI\arduino-cli.exe`
- config / cores / libraries: `C:\Users\Colto\AppData\Local\Arduino15\`
  and the sketchbook at `Documents\Arduino\`
- See your config any time: `arduino-cli config dump`
