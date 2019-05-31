#include <NMEA0183.h>
#include <NMEA0183Messages.h>
tNMEA0183Msg NMEA0183Msg;
tNMEA0183 NMEA0183;

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


struct {
  tRMB RMB;
  tRMC RMC;
} navInfo;


void setup() {
  NMEA0183.SetMsgHandler(HandleNMEA0183Msg);

  lcd.begin(16, 2);
  Serial.begin(9600);
  NMEA0183.SetMessageStream(&Serial);

  NMEA0183.Open();
}


void loop() {
  NMEA0183.ParseMessages();

  { // update the LCD
    lcd.home();
    lcd.clear();

    lcd.print("COG: ");
    lcd.print(radToDeg(navInfo.RMC.trueCOG));

    lcd.setCursor(0, 1);
    lcd.print("BRG: ");
    lcd.print(radToDeg(navInfo.RMB.btw));
  }

  delay(100);
}


void HandleNMEA0183Msg(const tNMEA0183Msg &NMEA0183Msg) {
  // We only parse "RMB" and "RMC" messages from our plotter
  if (NMEA0183Msg.IsMessageCode("RMB")){
    NMEA0183ParseRMB_nc(NMEA0183Msg, navInfo.RMB);

  } else if (NMEA0183Msg.IsMessageCode("RMC")) {
    NMEA0183ParseRMC_nc(NMEA0183Msg, navInfo.RMC.GPSTime, navInfo.RMC.latitude,
                        navInfo.RMC.longitude, navInfo.RMC.trueCOG,
                        navInfo.RMC.SOG, navInfo.RMC.daysSince1970,
                        navInfo.RMC.variation);
  }
}


inline double radToDeg(double rad) {
  // aproximate radians to degrees converstion without floats
  return rad * 4068 / 71;
}
