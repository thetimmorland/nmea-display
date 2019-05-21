#include <NMEA0183.h>
#include <NMEA0183Msg.h>

#include "nmea-handler.h"

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
