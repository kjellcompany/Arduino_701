/*
  Example sketch BlinkLed.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/

void setup() {
  
  // Use GPIO Pin 13 as output.
  pinMode(13, OUTPUT);
}

void loop() {

  // Turn on built in LED and then wait 1000 ms.
  digitalWrite(13, HIGH);
  delay(1000); 
  
  // Turn off built in LED and then wait 1000 ms.
  digitalWrite(13, LOW);
  delay(1000); 
}
