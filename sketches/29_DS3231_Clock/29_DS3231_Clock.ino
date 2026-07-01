/*
 * 29_DS3231_Clock
 * The DS3231 is a battery-backed real-time clock on the I2C bus. It keeps the
 * date and time even when the Arduino is off. We read it once a second and
 * print it so .\scripts\monitor.ps1 becomes a ticking clock.
 *
 * Library: RTClib (install with .\scripts\install-libs.ps1)
 *
 * Wiring (Mega 2560, I2C):
 *   VCC -> 5V   GND -> GND   SDA -> pin 20 (SDA)   SCL -> pin 21 (SCL)
 *
 * Watch it:  .\scripts\upload.ps1 29_DS3231_Clock  then  .\scripts\monitor.ps1
 */

#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println("DS3231 not found - check the I2C wiring.");
  }
  if (rtc.lostPower()) {                         // first run / dead battery
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));   // set to PC build time
  }
  Serial.println("DS3231 clock ready.");
}

void loop() {
  DateTime now = rtc.now();
  char buf[20];
  sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d",
          now.year(), now.month(), now.day(),
          now.hour(), now.minute(), now.second());
  Serial.println(buf);
  delay(1000);
}
