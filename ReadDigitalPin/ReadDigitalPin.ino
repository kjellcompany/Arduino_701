/*
  Example sketch ReadDigitalPin.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


void setup() {
  
  // Use GPIO Pin 13 as input.
  pinMode(13, INPUT);
}

void loop() {
  
  // Read GPIO Pin 13
  digitalRead(13);
}
