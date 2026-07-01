/*
 * 13_Flame_Sensor
 * A flame sensor is an infrared photodiode tuned to the light a flame gives
 * off. Closer/bigger flame -> more IR -> LOWER analog reading on A0. When the
 * reading drops past a threshold we sound the buzzer (a fire alarm!) and
 * narrate it over Serial so .\scripts\monitor.ps1 shows safe vs. alarm.
 *
 * Wiring (Mega 2560):
 *   Flame AO -> A0      Flame VCC -> 5V      Flame GND -> GND
 *   Buzzer (+) -> pin 8      Buzzer (-) -> GND
 *
 * Watch it:  .\scripts\upload.ps1 13_Flame_Sensor  then  .\scripts\monitor.ps1
 */

int flamePin  = A0;
int buzzerPin = 8;
int threshold = 200;     // lower = closer flame; tune to your sensor

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Flame sensor armed - keep flames away!");
}

void loop() {
  int flame = analogRead(flamePin);

  if (flame < threshold) {
    digitalWrite(buzzerPin, HIGH);
    Serial.print("FLAME DETECTED! buzzer ON  (analog=");
    Serial.print(flame);
    Serial.println(")");
  } else {
    digitalWrite(buzzerPin, LOW);
    Serial.print("safe (analog=");
    Serial.print(flame);
    Serial.println(")");
  }
  delay(200);
}
