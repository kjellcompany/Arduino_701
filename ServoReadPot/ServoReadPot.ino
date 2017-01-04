/*
  Example sketch ServoReadPot.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


// Include the servo library
#include <Servo.h>

// Create a new servo object
Servo pointer;  

// Declare constants for input and output
const byte potPin = A0;
const byte servoPin = 9;

int pos;

void setup() {
  
  // Attach the servo on pin 9 to the servo object
  pointer.attach(servoPin); 
  pinMode(potPin, INPUT);
}

void loop() {
  
  // Read potentiometer value and map scale
  pos = map(analogRead(potPin), 0, 1023, 0, 180);

  // Move servo
  pointer.write(pos);             
  delay(15);                   
}

