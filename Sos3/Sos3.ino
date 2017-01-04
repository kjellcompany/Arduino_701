/*
  Example sketch Sos3.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


// Include the Button and MorsePulse library
#include <Button.h>
#include <MorsePulse.h>

// Create a button object
Button btnSos(2);

// Create new MorsePulse objects
MorsePulse blinker(13, 200);
MorsePulse beeper(10, 200);

void setup() {

  // Start button
  btnSos.begin();
}


void loop() {
  
  // Start blinking and beeping
  if (btnSos.pressed()){
    
    // Blink and beep until btnSos is released
    while(!btnSos.released()){
      blinker.pulseText("sos");
      beeper.pulseText("sos");
    }
  }
}
