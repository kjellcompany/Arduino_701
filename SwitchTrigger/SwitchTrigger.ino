/*
  Example sketch SwitchTrigger.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


void setup() {
  
  // Use GPIO Pin 2 as input.
  pinMode(2, INPUT);

  // Open serial connection at 9600 Bd.
  Serial.begin(9600);
}

void loop() {
  
  // Print switch status in Serial monitor.
  Serial.print(digitalRead(2));
  delay(100);
}
