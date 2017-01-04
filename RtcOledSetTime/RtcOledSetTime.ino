/*
  Example sketch RtcOledSetTime.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  Using example code from the Rtc by Makuna Library
  https://github.com/Makuna/Rtc

  This code is in the public domain.
*/


// Include the libraries
#include <RtcDS3231.h>
#include <Wire.h> 

// Create new RTC module object
RtcDS3231 rtcModule;

void setup () {

  // Enable I2C communication
  Wire.begin();

  // Update RTC module time to compilation time
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  rtcModule.SetDateTime(compiled);
}

void loop(void) {

}

