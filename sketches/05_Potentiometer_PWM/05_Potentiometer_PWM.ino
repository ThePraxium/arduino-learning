/*
 * 05_Potentiometer_PWM - turn the knob to control LED brightness.
 * Reads the potentiometer on A0 and uses it to set PWM brightness on pin 10.
 * Also prints the live values so you can watch them in the serial monitor.
 *
 * Wiring:
 *   Pot left leg  -> 5V        Pot middle leg -> A0        Pot right leg -> GND
 *   LED circuit unchanged (pin 10 -> resistor -> LED -> GND)
 *
 * Board:  Inland / Keyestudio Mega 2560 R3
 * Upload: .\scripts\upload.ps1 05_Potentiometer_PWM
 * Watch:  .\scripts\monitor.ps1
 */

int ledPin = 10;           // LED on a PWM (~) pin
int potPin = A0;           // potentiometer middle leg

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);      // open the serial link so we can print values
}

void loop() {
  int potValue = analogRead(potPin);                 // read the knob: 0..1023
  int brightness = map(potValue, 0, 1023, 0, 255);   // rescale to 0..255
  analogWrite(ledPin, brightness);                   // set LED brightness

  Serial.print("knob: ");
  Serial.print(potValue);
  Serial.print("   brightness: ");
  Serial.println(brightness);

  delay(50);               // small pause so the serial text isn't a blur
}
