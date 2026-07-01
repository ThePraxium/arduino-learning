/*
 * 14_LM35_Temperature
 * The LM35 outputs a voltage straight in proportion to temperature:
 * 10 mV per degree C. Read that voltage on A0, do a little math, and you have
 * degrees C - no library needed. We print the temperature once a second so
 * .\scripts\monitor.ps1 becomes a live thermometer.
 *
 * Wiring (Mega 2560), flat side facing you, legs down:
 *   left leg  -> 5V       middle leg -> A0       right leg -> GND
 *
 * Watch it:  .\scripts\upload.ps1 14_LM35_Temperature  then  .\scripts\monitor.ps1
 */

int lm35Pin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("LM35 thermometer ready.");
}

void loop() {
  int   raw   = analogRead(lm35Pin);        // 0..1023
  float volts = raw * (5.0 / 1023.0);       // convert to volts
  float tempC = volts * 100.0;              // 10 mV per degree -> *100

  Serial.print("temp = ");
  Serial.print(tempC, 1);
  Serial.println(" C");
  delay(1000);
}
