/*
 * 15_Tilt_Switch   (Inland kit Project 13)
 * A tilt switch is a tube with a metal ball: tip it one way and the ball
 * bridges two contacts (closed), tip it back and the circuit opens. Wired
 * like a button (with a 10k pull-down), it reads HIGH when tilted, LOW when
 * level. The LED follows, and we narrate each flip so .\scripts\monitor.ps1
 * shows the orientation change.
 *
 * Wiring (Mega 2560):
 *   Tilt: one leg -> 5V; other leg -> pin 2 AND through 10k -> GND
 *   LED:  pin 8 -> 220 -> LED(+);  LED(-) -> GND
 *
 * Watch it:  .\scripts\upload.ps1 15_Tilt_Switch  then  .\scripts\monitor.ps1
 */

int tiltPin   = 2;
int ledPin    = 8;
int lastState = LOW;

void setup() {
  pinMode(tiltPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Tilt switch ready - tip the breadboard!");
}

void loop() {
  int state = digitalRead(tiltPin);
  digitalWrite(ledPin, state);

  if (state != lastState) {
    Serial.println(state == HIGH ? "tilted -> LED ON" : "level  -> LED OFF");
    lastState = state;
  }
  delay(20);
}
