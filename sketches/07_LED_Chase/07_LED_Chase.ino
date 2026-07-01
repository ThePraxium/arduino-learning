/*
 * 07_LED_Chase - smooth "flowing water" chase across 6 LEDs.
 * Six LEDs on pins 2..7, each through a 220 ohm resistor to the shared (-) rail.
 * One glow flows left-to-right then back, FADING smoothly from each LED into the
 * next (a crossfade) instead of snapping on and off.
 *
 * Two ideas at work:
 *   ARRAY + FOR-LOOP   - keep all six pins in a list and step through them.
 *   analogWrite (PWM)  - set a brightness 0..255 instead of just on/off, which is
 *                        what makes a fade possible. On the Mega, pins 2..13 can
 *                        do this, so pins 2..7 all qualify.
 *
 * It also PRINTS each step over USB so you can follow the code live:
 *   .\scripts\monitor.ps1            (9600 baud, matches Serial.begin below)
 *
 * Board:  Inland / Keyestudio Mega 2560 R3
 * Upload: .\scripts\upload.ps1 07_LED_Chase
 */

int ledPins[] = {2, 3, 4, 5, 6, 7};  // the 6 pins, in order, as a list
int numLeds   = 6;                   // how many LEDs are in the list
int fadeMs    = 350;                 // ms to fade one LED into the next (smaller = faster)
int steps     = 60;                  // brightness steps per fade (bigger = smoother)

void setup() {
  Serial.begin(9600);                // open the USB serial link at 9600 baud
  Serial.println("LED chase starting...");

  // set every pin in the list to OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  analogWrite(ledPins[0], 255);      // start with the first LED lit, ready to fade
}

// Hand the glow from one LED to the next, smoothly.
// fromIdx dims 255 -> 0 while toIdx brightens 0 -> 255, at the same time.
void crossfade(int fromIdx, int toIdx, const char *dir) {
  Serial.print(dir);
  Serial.print("  ->  LED ");
  Serial.print(toIdx + 1);           // human-friendly: LED 1..6
  Serial.print("  (pin ");
  Serial.print(ledPins[toIdx]);      // the actual pin number
  Serial.println(")");

  for (int s = 0; s <= steps; s++) {
    int b = (255 * s) / steps;               // brightness rising 0..255
    analogWrite(ledPins[toIdx], b);          // next LED fades up
    analogWrite(ledPins[fromIdx], 255 - b);  // current LED fades down
    delay(fadeMs / steps);
  }
}

void loop() {
  // sweep forward: 0 -> 1 -> 2 -> 3 -> 4 -> 5
  for (int i = 1; i < numLeds; i++) {
    crossfade(i - 1, i, "forward ");
  }

  // sweep backward: 5 -> 4 -> 3 -> 2 -> 1 -> 0
  for (int i = numLeds - 2; i >= 0; i--) {
    crossfade(i + 1, i, "backward");
  }
}
