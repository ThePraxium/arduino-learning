/*
 * 10_Passive_Buzzer
 * A PASSIVE buzzer has NO oscillator of its own - it is a tiny speaker.
 * YOU must feed it a frequency with tone(). Different frequencies = different
 * pitches, so we can play a melody. Here we walk up a C-major scale and
 * narrate each note over Serial so .\scripts\monitor.ps1 names what you hear.
 *
 * Wiring (Mega 2560):
 *   Buzzer (+) -> pin 8        Buzzer (-) -> GND
 *
 * Watch it:  .\scripts\upload.ps1 10_Passive_Buzzer  then  .\scripts\monitor.ps1
 */

int buzzerPin = 8;
int   melody[] = { 262, 294, 330, 349, 392, 440, 494, 523 };  // C4..C5 in Hz
const char* names[] = { "C4", "D4", "E4", "F4", "G4", "A4", "B4", "C5" };
int numNotes = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Passive buzzer ready - playing a scale.");
}

void loop() {
  for (int i = 0; i < numNotes; i++) {
    tone(buzzerPin, melody[i]);              // start this frequency
    Serial.print("tone: ");
    Serial.print(names[i]);
    Serial.print(" (");
    Serial.print(melody[i]);
    Serial.println(" Hz)");
    delay(350);
  }
  noTone(buzzerPin);                          // silence between repeats
  Serial.println("(silence)");
  delay(800);
}
