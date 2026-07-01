/*
 * 30_DHT11   (Inland kit Project 30)
 * The DHT11 measures temperature AND humidity and sends both over a single
 * data wire. The DHT library does the tricky timing; we just ask for the two
 * numbers every couple of seconds and print them so .\scripts\monitor.ps1
 * shows the room's climate.
 *
 * Library: DHT sensor library + Adafruit Unified Sensor (.\scripts\install-libs.ps1)
 *
 * Wiring (Mega 2560), module pins:
 *   VCC/+ -> 5V    DATA/S -> pin 8    GND/- -> GND
 *
 * Watch it:  .\scripts\upload.ps1 30_DHT11  then  .\scripts\monitor.ps1
 */

#include <DHT.h>

#define DHTPIN  8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT11 temperature + humidity ready.");
}

void loop() {
  float t = dht.readTemperature();    // degrees C
  float h = dht.readHumidity();       // percent

  if (isnan(t) || isnan(h)) {
    Serial.println("DHT read failed - retrying...");
  } else {
    Serial.print("temp=");
    Serial.print(t, 1);
    Serial.print("C  humidity=");
    Serial.print(h, 0);
    Serial.println("%");
  }
  delay(2000);                        // DHT11 is slow; don't poll too fast
}
