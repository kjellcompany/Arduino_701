/*
  Example sketch FourLed.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/



const byte ledPins[4] = {6, 9, 10, 11};

void setup() {
  
  // Use GPIO pin 6, 9, 10 and 11 as output
  for(int i = 0; i <= 3; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  
  // Turn on LED
  for(int i = 0; i <= 3; i++){
    digitalWrite(ledPins[i], HIGH);
    delay(250);
  }

  // Turn off LED
  for(int i = 0; i <= 3; i++){
    digitalWrite(ledPins[i], LOW);
    delay(250);
  }
}
