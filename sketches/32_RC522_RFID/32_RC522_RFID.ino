/*
 * 32_RC522_RFID   (Inland kit Project 32)
 * The RC522 reads 13.56 MHz RFID cards/fobs over SPI. Each card has a unique
 * ID (UID). When you tap a card we read its UID and print it so
 * .\scripts\monitor.ps1 shows the card - the basis of any access-card system.
 *
 * Library: MFRC522 (install with .\scripts\install-libs.ps1)
 *
 * Wiring (Mega 2560, SPI):
 *   SDA(SS) -> pin 53   SCK -> pin 52   MOSI -> pin 51   MISO -> pin 50
 *   RST -> pin 5        3.3V -> 3V3     GND -> GND
 *
 * Watch it:  .\scripts\upload.ps1 32_RC522_RFID  then  .\scripts\monitor.ps1
 */

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN  53
#define RST_PIN 5

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("RC522 ready - tap a card or fob.");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;   // nothing on the reader
  if (!rfid.PICC_ReadCardSerial())  return;    // couldn't read it

  Serial.print("card UID:");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(' ');
    if (rfid.uid.uidByte[i] < 0x10) Serial.print('0');
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();

  rfid.PICC_HaltA();                           // stop reading this card
  delay(500);
}
