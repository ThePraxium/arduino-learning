/*
 * 12_Photoresistor   (Inland kit Project 10)
 * A photoresistor (LDR) changes resistance with light. Wired as a voltage
 * divider with a 10k resistor, it turns "how bright is the room" into a
 * number on analog pin A0 (0..1023). We use that number to set an LED's
 * brightness, and narrate both values over Serial so .\scripts\monitor.ps1
 * shows the light reading drive the LED.
 *
 * Wiring (Mega 2560):
 *   LDR leg1 -> 5V       LDR leg2 -> A0 AND through 10k -> GND  (divider)
 *   LED: pin 9 -> 220 -> LED(+);  LED(-) -> GND
 *
 * Watch it:  .\scripts\upload.ps1 12_Photoresistor  then  .\scripts\monitor.ps1
 */

int ldrPin = A0;     // photoresistor divider midpoint
int ledPin = 9;      // LED on a PWM (~) pin

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Photoresistor ready - shade it to change the LED.");
}

void loop() {
  int light = analogRead(ldrPin);                  // 0 (dark) .. 1023 (bright)
  int brightness = map(light, 0, 1023, 0, 255);    // rescale to PWM range
  analogWrite(ledPin, brightness);

  Serial.print("light=");
  Serial.print(light);
  Serial.print(" -> brightness=");
  Serial.println(brightness);
  delay(120);
}
