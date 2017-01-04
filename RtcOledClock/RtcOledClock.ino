/*
  Example sketch RtcOledClock.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  Using example code from the Universal 8bit Graphics Library
  https://github.com/olikraus/u8glib/

  Using example code from the Rtc by Makuna Library
  https://github.com/Makuna/Rtc

  This code is in the public domain.
*/

// Include the libraries
#include <RtcDS3231.h>
#include "U8glib.h"
#include <Wire.h> 


// Create new SSD1306 I2C display with 128x64 resolution
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);  // I2C / TWI 

// Create new RTC module
RtcDS3231<TwoWire> rtcModule(Wire);

// Create variables for time
byte hours;
byte minutes;
byte seconds;

void setup () {

}

void loop() {
  
  // Refresh picture
  oled.firstPage();  
  do {
    draw();
  } while(oled.nextPage());
  delay(20);
  updateTime();
}

void updateTime() {
   RtcDateTime now = rtcModule.GetDateTime();
   hours = now.Hour();
   minutes = now.Minute();
   seconds = now.Second();
} 

void draw(void) {
  
  // Set font to Helvetica size 24
  oled.setFont(u8g_font_helvB24);

  // Format and print time on display
  char timeString[10];
  sprintf(timeString, "%02u:%02u:%02u", hours, minutes, seconds);
  oled.setPrintPos(0, 45);
  oled.print(timeString);
}


