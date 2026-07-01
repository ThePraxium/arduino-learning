/*
 * 27_Joystick   (Inland kit Project 27)
 * A joystick is just two potentiometers (X and Y) plus a push button (SW).
 * Read X and Y on analog pins (0..1023, centre ~512) and the button on a
 * digital pin. We stream all three over Serial so .\scripts\monitor.ps1
 * shows the stick move and click in real time.
 *
 * Wiring (Mega 2560):
 *   +5V -> 5V    GND -> GND    VRx -> A0    VRy -> A1    SW -> pin 2
 *
 * Watch it:  .\scripts\upload.ps1 27_Joystick  then  .\scripts\monitor.ps1
 */

int xPin  = A0;
int yPin  = A1;
int swPin = 2;

void setup() {
  pinMode(swPin, INPUT_PULLUP);    // button idles HIGH, reads LOW when pressed
  Serial.begin(9600);
  Serial.println("Joystick ready - move and press.");
}

void loop() {
  int x  = analogRead(xPin);
  int y  = analogRead(yPin);
  int sw = digitalRead(swPin);

  Serial.print("X:");   Serial.print(x);
  Serial.print("  Y:"); Serial.print(y);
  Serial.print("  SW:"); Serial.println(sw == LOW ? "PRESSED" : "up");
  delay(150);
}
