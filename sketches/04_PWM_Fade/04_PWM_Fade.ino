/*
 * 04_PWM_Fade - smoothly fade the LED brighter and dimmer (no on/off).
 * Uses analogWrite() / PWM on pin 10. Same wiring as 03_LED_Blink.
 *
 * Board:  Inland / Keyestudio Mega 2560 R3
 * Upload: .\scripts\upload.ps1 04_PWM_Fade
 */

int ledPin = 10;           // must be a PWM (~) pin; 10 qualifies

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // fade UP: walk brightness from 0 (off) to 255 (full)
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);  // set this brightness level
    delay(5);                         // tiny pause so the fade is visible
  }

  // fade DOWN: walk brightness from 255 back to 0
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(5);
  }
}
