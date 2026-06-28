# Inland Super Starter Kit (Mega 2560 R3) — Component Reference

Micro Center SKU **052043**. The board is a Keyestudio-made Mega 2560 R3
(ATmega2560, 16 MHz, 256 KB flash, 8 KB SRAM, 4 KB EEPROM). 32 tutorial projects.

FQBN for arduino-cli: **`arduino:avr:mega`**

## What's in the box

| Component | Qty | Typical use / notes |
|-----------|-----|---------------------|
| Mega 2560 R3 board | 1 | The microcontroller. 54 digital pins, 16 analog inputs. |
| 830-point breadboard | 1 | Solderless prototyping. |
| LEDs — red / yellow / blue | 5 each | Use a 220Ω resistor in series. |
| RGB LED | 1 | Common-cathode; 3 PWM pins + ground. |
| Resistors 220Ω | 8 | Current-limiting for LEDs. |
| Resistors 1KΩ | 5 | General purpose. |
| Resistors 10KΩ | 5 | Pull-up/pull-down, dividers. |
| Potentiometer 10KΩ | 1 | Analog input (analogRead). |
| Active buzzer | 1 | Makes a fixed tone with DC. |
| Passive buzzer | 1 | Needs a PWM/tone() signal to make pitches. |
| Push buttons | 4 | Use INPUT_PULLUP to avoid floating. |
| Ball tilt sensor | 2 | Simple orientation/shake switch. |
| Photoresistor (LDR) | 3 | Light sensing via voltage divider. |
| Flame sensor | 1 | IR-based flame detection. |
| LM35 temp sensor | 1 | Analog temperature (10 mV/°C). |
| 74HC595 shift register | 1 | Adds 8 outputs from 3 pins (drives 7-seg / matrix). |
| 1-digit 7-segment display | 1 | Single digit. |
| 4-digit 7-segment display | 1 | Multiplexed 4-digit. |
| 8x8 LED matrix | 1 | Often driven via 74HC595. |
| 1602 LCD (16x2) | 1 | Parallel LCD; LiquidCrystal library. |
| IR receiver + remote | 1 | IRremote library. |
| Servo motor (SG90-class) | 1 | Servo library; signal on a PWM pin. |
| ULN2003 stepper driver + 28BYJ-48 stepper | 1 | Stepper library / custom stepping. |
| Joystick module | 1 | 2 analog axes + button. |
| Relay module | 1 | Switch higher-voltage loads. |
| PIR motion sensor | 1 | Digital motion detection. |
| Analog gas sensor (MQ-series) | 1 | Smoke/gas; analog output. |
| ADXL345 accelerometer | 1 | 3-axis, I2C/SPI. |
| HC-SR04 ultrasonic | 1 | Distance via trig/echo pins. |
| DS3231 RTC module | 1 | Real-time clock, I2C. RTClib. |
| DHT11 | 1 | Temp + humidity, single-wire. DHT library. |
| Soil moisture sensor | 1 | Analog output. |
| RC522 RFID + card + fob | 1 | 13.56 MHz RFID, SPI. MFRC522 library. |
| Pin headers (40) | — | For modules/protoboards. |
| Jumper wires + Dupont wires | 30 + 10 | Connections. |
| 6×AA battery pack | 1 | Untethered power. |
| USB cable (Type-B) | 1 | Programming + power from PC. |

## Mega 2560 pin cheat-sheet

- **Digital I/O:** pins 0–53. Pins **0/1** are also Serial (USB) — avoid using them
  for other things while debugging over USB.
- **PWM (`analogWrite`):** pins 2–13 and 44–46.
- **Analog inputs (`analogRead`):** A0–A15.
- **I2C:** SDA = pin 20, SCL = pin 21. (DS3231, ADXL345.)
- **SPI:** MOSI 51, MISO 50, SCK 52, SS 53. (RC522, etc.)
- **On-board LED:** pin 13 (`LED_BUILTIN`).
- **External interrupts:** pins 2, 3, 18, 19, 20, 21.

## Library → component map

Install with: `.\scripts\install-libs.ps1` (or `arduino-cli lib install "<name>"`).

| Library | Used by |
|---------|---------|
| `LiquidCrystal` (bundled w/ core) | 1602 LCD |
| `DHT sensor library` + `Adafruit Unified Sensor` | DHT11 |
| `IRremote` | IR receiver + remote |
| `Servo` (bundled w/ core) | Servo motor |
| `Stepper` (bundled w/ core) | 28BYJ-48 stepper |
| `RTClib` | DS3231 clock |
| `MFRC522` | RC522 RFID |
| `Adafruit ADXL345` + `Adafruit Unified Sensor` | ADXL345 accelerometer |
