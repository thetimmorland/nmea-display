#include <NMEA0183.h>
#include <NMEA0183Msg.h>
#include <LiquidCrystal.h>

#include "nmea-handler.h"

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

tNMEA0183Msg NMEA0183Msg;
tNMEA0183 NMEA0183;

void setup() {
  NMEA0183.SetMsgHandler(DisplayNMEA0183Msg);

  Serial.begin(9600);
  NMEA0183.SetMessageStream(&Serial);
  NMEA0183.Open();
}

void loop() {
  NMEA0183.ParseMessages();
}
