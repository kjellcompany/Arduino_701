/*
  Example sketch PwmLed.ino version 7.01.
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
  // Fade up LED
  for(int i = 0; i <= 3; i++){
    for(int j = 0; j <= 255; j++){
      analogWrite(ledPins[i], j);
      delay(1);
    }
  }

  // Fade down LED
  for(int i = 0; i <= 3; i++){
    for(int j = 255; j >= 0; j--){
      analogWrite(ledPins[i], j);
      delay(1);
    }
  }
}
