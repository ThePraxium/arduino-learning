/*
 * 01_Blink - the "hello world" of Arduino.
 * Blinks the on-board LED (pin 13 / LED_BUILTIN) once per second.
 *
 * Board: Inland / Keyestudio Mega 2560 R3
 * Upload:  .\scripts\upload.ps1 01_Blink
 */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // LED on
  delay(1000);                       // wait 1 second
  digitalWrite(LED_BUILTIN, LOW);    // LED off
  delay(1000);                       // wait 1 second
}
