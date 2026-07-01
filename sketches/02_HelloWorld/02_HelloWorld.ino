/*
 * 02_HelloWorld - the kit's first project.
 * Prints "Hello World!" over serial. Send the letter 'R' from the
 * serial monitor to blink the on-board LED and reprint the message.
 *
 * Wiring: none - just the USB cable.
 * Board:  Inland / Keyestudio Mega 2560 R3
 * Upload: .\scripts\upload.ps1 02_HelloWorld
 * View:   .\scripts\monitor.ps1   (9600 baud)
 */

char val;                 // holds the incoming character
int ledPin = 13;          // on-board LED

void setup() {
  Serial.begin(9600);     // open serial at 9600 baud
  pinMode(ledPin, OUTPUT);
  Serial.println("Hello World!");
}

void loop() {
  if (Serial.available()) {     // did we receive anything?
    val = Serial.read();        // read one character
    if (val == 'R') {           // capital R?
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
      Serial.println("Hello World!");
    }
  }
}
