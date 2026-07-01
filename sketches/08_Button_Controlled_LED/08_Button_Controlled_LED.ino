/*
 * 08_Button_Controlled_LED
 * Your first INPUT project: until now the Arduino only TALKED (it drove
 * LEDs). Now it also LISTENS - it reads a push button and reacts, and it
 * NARRATES every change over Serial so .\scripts\monitor.ps1 shows it live.
 *
 * How it works:
 *   - Button on pin 2 with a 10k "pull-down" resistor to GND.
 *   - Not pressed: the 10k quietly ties pin 2 to GND -> reads LOW.
 *   - Pressed:     the button connects 5V to pin 2    -> reads HIGH.
 *   - Each press TOGGLES the LED on pin 8: on -> off -> on...
 *     (we catch the LOW->HIGH edge so one push = one flip).
 *
 * Wiring (Mega 2560):
 *   Button: one side  -> 5V
 *           other side -> pin 2  AND  through 10k resistor -> GND
 *   LED:    pin 8 -> 220 ohm -> LED long leg (+); short leg (-) -> GND
 *
 * Watch it:  .\scripts\upload.ps1 08_Button_Controlled_LED
 *            .\scripts\monitor.ps1
 */

int buttonPin = 2;       // push button input (10k pull-down to GND)
int ledPin    = 8;       // LED output
int lastState = LOW;     // the button reading from the previous loop
bool ledOn    = false;   // the LED's remembered on/off state (survives between presses)

void setup() {
  pinMode(buttonPin, INPUT);    // this pin LISTENS for a voltage
  pinMode(ledPin, OUTPUT);      // this pin DRIVES the LED
  Serial.begin(9600);           // open the serial link for the monitor
  Serial.println("Toggle LED ready. Press to turn on, press again to turn off!");
}

void loop() {
  int buttonState = digitalRead(buttonPin);   // HIGH when pressed, LOW when not

  // Detect the MOMENT of a press: the button just went from LOW to HIGH.
  if (buttonState == HIGH && lastState == LOW) {
    ledOn = !ledOn;                           // flip the remembered state
    digitalWrite(ledPin, ledOn ? HIGH : LOW); // apply it to the LED

    Serial.println(ledOn ? "Press -> LED ON" : "Press -> LED OFF");
    delay(50);                                // debounce: ignore contact bounce
  }

  lastState = buttonState;                    // remember for the next loop
  delay(10);
}
