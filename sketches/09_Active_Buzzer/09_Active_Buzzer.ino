/*
 * 09_Active_Buzzer   (Inland kit Project 7)
 * An ACTIVE buzzer has its own oscillator inside: give it power and it
 * makes one fixed tone. So driving it is exactly like blinking an LED -
 * HIGH = sound, LOW = silence. We narrate each beep over Serial so
 * .\scripts\monitor.ps1 shows the rhythm the board is playing.
 *
 * Wiring (Mega 2560):
 *   Buzzer (+) long leg -> pin 8
 *   Buzzer (-) short leg -> GND
 *
 * Watch it:  .\scripts\upload.ps1 09_Active_Buzzer  then  .\scripts\monitor.ps1
 */

int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Active buzzer ready - beeping.");
}

void loop() {
  digitalWrite(buzzerPin, HIGH);   // power on  -> tone
  Serial.println("BEEP  (on)");
  delay(500);

  digitalWrite(buzzerPin, LOW);    // power off -> silence
  Serial.println("....  (off)");
  delay(500);
}
