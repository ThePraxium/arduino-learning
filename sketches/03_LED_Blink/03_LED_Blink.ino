/*
 * 03_LED_Blink - blink YOUR OWN LED on the breadboard (not the on-board one).
 * Turns an external LED on pin 8 on for 1s, off for 1s, forever.
 *
 * Wiring (see lesson):
 *   pin 8 --> 220ohm resistor --> LED long leg (+)
 *   LED short leg (-) --> GND
 *
 * Board:  Inland / Keyestudio Mega 2560 R3
 * Upload: .\scripts\upload.ps1 03_LED_Blink
 */

int ledPin = 10;           // the digital pin our LED is wired to

void setup() {
  pinMode(ledPin, OUTPUT);       // tell the board pin 8 is an output (it will send power out)
  pinMode(LED_BUILTIN, OUTPUT);  // DIAGNOSTIC: also drive the on-board light (pin 13)
}

void loop() {
  digitalWrite(ledPin, HIGH);       // send 5V out of pin 8 -> LED on
  digitalWrite(LED_BUILTIN, HIGH);  // on-board light on at the same time
  delay(1000);                      // wait 1000 ms (1 second)
  digitalWrite(ledPin, LOW);        // 0V -> LED off
  digitalWrite(LED_BUILTIN, LOW);   // on-board light off
  delay(1000);                      // wait 1 second
}
