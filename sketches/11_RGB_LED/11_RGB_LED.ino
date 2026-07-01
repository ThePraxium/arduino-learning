/*
 * 11_RGB_LED   (Inland kit Project 9)
 * An RGB LED is three LEDs (red, green, blue) in one dome sharing a common
 * cathode (-). By PWM-dimming each colour with analogWrite() and mixing them,
 * we make any colour. We narrate the current R,G,B mix over Serial so
 * .\scripts\monitor.ps1 shows exactly what the dome is displaying.
 *
 * Wiring (Mega 2560, common-cathode):
 *   R leg -> 220 -> pin 9       G leg -> 220 -> pin 10
 *   B leg -> 220 -> pin 11      common (longest) leg -> GND
 *
 * Watch it:  .\scripts\upload.ps1 11_RGB_LED  then  .\scripts\monitor.ps1
 */

int rPin = 9, gPin = 10, bPin = 11;   // all PWM (~) pins

void showColor(int r, int g, int b, const char* name) {
  analogWrite(rPin, r);
  analogWrite(gPin, g);
  analogWrite(bPin, b);
  Serial.print("R:");   Serial.print(r);
  Serial.print(" G:");  Serial.print(g);
  Serial.print(" B:");  Serial.print(b);
  Serial.print("   ("); Serial.print(name); Serial.println(")");
}

void setup() {
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("RGB LED ready - cycling colours.");
}

void loop() {
  showColor(255,   0,   0, "red");     delay(700);
  showColor(  0, 255,   0, "green");   delay(700);
  showColor(  0,   0, 255, "blue");    delay(700);
  showColor(255, 255,   0, "yellow");  delay(700);
  showColor(  0, 255, 255, "cyan");    delay(700);
  showColor(255,   0, 255, "magenta"); delay(700);
  showColor(255, 255, 255, "white");   delay(700);
}
