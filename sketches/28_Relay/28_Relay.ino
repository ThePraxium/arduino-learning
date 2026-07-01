/*
 * 28_Relay
 * A relay is an electrically-controlled mechanical switch: a small 5V signal
 * from the Arduino flips a much bigger circuit on or off (you hear it CLICK).
 * Driving it is just like an LED - HIGH energizes the coil. We toggle it on a
 * timer and narrate over Serial so .\scripts\monitor.ps1 shows each click.
 *
 * Wiring (Mega 2560):
 *   Relay IN -> pin 8     Relay VCC -> 5V     Relay GND -> GND
 *
 * Watch it:  .\scripts\upload.ps1 28_Relay  then  .\scripts\monitor.ps1
 */

int relayPin = 8;

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Relay ready - clicking on and off.");
}

void loop() {
  digitalWrite(relayPin, HIGH);                 // coil energized
  Serial.println("Relay ON  (click) -> NO contact closed");
  delay(1500);

  digitalWrite(relayPin, LOW);                  // coil released
  Serial.println("Relay OFF (click) -> NO contact open");
  delay(1500);
}
