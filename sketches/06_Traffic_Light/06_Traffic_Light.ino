/*
 * 06_Traffic_Light - one traffic-light cycle: green -> yellow -> red, repeating.
 * Three LEDs, each through its own 220 ohm resistor to a shared ground rail.
 *   green  -> pin 9
 *   yellow -> pin 10
 *   red    -> pin 11
 *
 * It also PRINTS each light over USB so you can follow the code live:
 *   .\scripts\monitor.ps1            (9600 baud, matches Serial.begin below)
 *
 * Board:  Mega 2560 (ATmega2560)
 * Upload: .\scripts\upload.ps1 06_Traffic_Light
 */

int greenPin  = 9;
int yellowPin = 10;
int redPin    = 11;

void setup() {
  pinMode(greenPin,  OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin,    OUTPUT);
  Serial.begin(9600);
  Serial.println("Traffic light starting...");
}

void loop() {
  // GREEN - go (5 seconds)
  digitalWrite(greenPin, HIGH);
  Serial.println("GREEN  - go        (5s)");
  delay(5000);
  digitalWrite(greenPin, LOW);

  // YELLOW - get ready to stop (2 seconds)
  digitalWrite(yellowPin, HIGH);
  Serial.println("YELLOW - slow down (2s)");
  delay(2000);
  digitalWrite(yellowPin, LOW);

  // RED - stop (5 seconds)
  digitalWrite(redPin, HIGH);
  Serial.println("RED    - stop      (5s)");
  delay(5000);
  digitalWrite(redPin, LOW);
}
