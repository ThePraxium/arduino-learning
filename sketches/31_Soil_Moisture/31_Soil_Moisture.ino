/*
 * 31_Soil_Moisture
 * The soil sensor's two prongs measure how easily current passes through the
 * soil: wetter soil conducts better, giving a higher reading on A0. Read it,
 * label it dry/damp/wet, and narrate over Serial so .\scripts\monitor.ps1
 * becomes a plant-watering meter.
 *
 * Wiring (Mega 2560):
 *   Sensor + -> 5V     Sensor - -> GND     Sensor A0 -> A0
 *
 * Watch it:  .\scripts\upload.ps1 31_Soil_Moisture  then  .\scripts\monitor.ps1
 */

int soilPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("Soil moisture sensor ready.");
}

void loop() {
  int m = analogRead(soilPin);                 // dry ~ low, wet ~ high
  const char* label = (m < 300) ? "dry" : (m < 700) ? "damp" : "wet";

  Serial.print("moisture=");
  Serial.print(m);
  Serial.print("  (");
  Serial.print(label);
  Serial.println(")");
  delay(800);
}
