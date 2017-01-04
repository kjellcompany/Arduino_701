/*
  Example sketch BlinkLedBinary.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/

void setup() {
  
  // Use GPIO Pin 13 as output.
  pinMode(13, OUTPUT);
}

void loop() {
  
  // Turn on LED and then wait 1000 ms.
  digitalWrite(13, true);
  delay(1000); 
  
  // Turn off LED and then wait 1000 ms.
  digitalWrite(13, 0);
  delay(1000); 
}
