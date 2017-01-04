/*
  Example sketch PwmRgbLed.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/



// Set ledPin[0] as red
// Set ledPin[1] as green
// Set ledPin[2] as blue
const byte ledPins[3] = {9, 10, 11};

void setup() {
  
  // Use GPIO pin 9, 10 and 11 as output
  for(int i = 0; i <= 2; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  
  // Fade to red
  for(int i = 0; i <= 255; i++){
    analogWrite(ledPins[0], i);
    delay(5);
  }

  //Fade from red to green
  for(int i = 0; i <= 255; i++){
    analogWrite(ledPins[0], 255 - i);
    analogWrite(ledPins[1], i);
    delay(5);
  }

  //Fade from green to blue
  for(int i = 0; i <= 255; i++){
    analogWrite(ledPins[1], 255 - i);
    analogWrite(ledPins[2], i);
    delay(5);
  }

  //Fade away
  for(int i = 0; i <= 255; i++){
    analogWrite(ledPins[2], 255 - i);
    delay(5);
  }
}
