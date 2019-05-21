#include <NMEA0183.h>
#include <NMEA0183Msg.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void DisplayNMEA0183Msg(const tNMEA0183Msg &NMEA0183Msg) {
  if (NMEA0183Msg.IsMessageCode("RMB")) {
    lcd.print("RMB");

  } else if (NMEA0183Msg.IsMessageCode("RMC")) {
    lcd.print("RMC");

  } else {
    lcd.print("?");
  }
}
