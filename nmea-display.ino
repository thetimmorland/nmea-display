#include <LiquidCrystal.h>
#include "NMEA0183/NMEA0183.h"

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  if (Serial.available()) {
    lcd.write(Serial.read());
  }
}
