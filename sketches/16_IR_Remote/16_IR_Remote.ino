/*
 * 16_IR_Remote
 * The IR receiver listens for the coded pulses from the remote control. The
 * IRremote library decodes each press into a number; we print which button
 * was pressed over Serial so .\scripts\monitor.ps1 reacts to your remote.
 *
 * Library: IRremote (install with .\scripts\install-libs.ps1)
 *
 * Wiring (Mega 2560), receiver bulged side facing you:
 *   left leg -> pin 11 (signal)   middle leg -> GND   right leg -> 5V
 *
 * Watch it:  .\scripts\upload.ps1 16_IR_Remote  then  .\scripts\monitor.ps1
 */

#include <IRremote.hpp>

int RECV_PIN = 11;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);   // start listening
  Serial.println("IR remote ready - point and press a button.");
}

void loop() {
  if (IrReceiver.decode()) {                          // a code arrived
    Serial.print("button: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    IrReceiver.resume();                              // ready for the next press
  }
}
