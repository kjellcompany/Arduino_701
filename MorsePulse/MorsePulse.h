/*
  Part of MorsePulse library version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


#ifndef MorsePulse_h
#define MorsePulse_h

#include "Arduino.h"

class MorsePulse {
  public:
    MorsePulse(byte ledPin, unsigned long morseSpeed);
    void pulseLetter(char character);
    void pulseText(String text);
    
  private:
    byte _ledPin;
    unsigned long _morseSpeed; 
    void shortPulse(byte pulses);
    void longPulse(byte pulses);
    void nextWord();
    void nextLetter();
};

#endif