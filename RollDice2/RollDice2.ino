/*
  Example sketch RollDice2.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


// Include the button and servo library
#include <Button.h>
#include <Servo.h>

// Create a button object on GPIO pin 13
Button btnRoll(13);

// Create a new servo object
Servo servo; 

// Declare global pin constant for buzzer
const byte buzzerPin = 10;

void setup() {

  // Set buzzerPin as output
  pinMode(buzzerPin, OUTPUT);

  // Start button
  btnRoll.begin();
  
  // Attach the servo on pin 9 to the servo object
  servo.attach(9);

  // Initialise a pseudo-random number generator
  randomSeed(analogRead(0)); 

  // Move servo to position zero
  servo.write(0);

  // Show steps for calibration
  for(int i = 1; i < 7; i++){
     setDice(i, true);
     delay(1000);
  }
}

void loop() {
  
  // Roll dice
  if (btnRoll.released()) {
    upDown();
    setDice(random(1, 7), true);
  }
}

void upDown() {
  
  // Move servo up and down
  setDice(6, false);
  delay(600);
  setDice(1, false);
  delay(600);
}

void setDice(int number, boolean acousticFeedback) {
  
  // Map scale
  int dicePointer = map(number, 1, 6, 20, 140); 

  // Move servo
  servo.write(dicePointer);

  // Play sound
  if(acousticFeedback == true){
    delay(500);
    for(int i = 0; i < number; i++){
      digitalWrite(buzzerPin, HIGH);
      delay(125);
      digitalWrite(buzzerPin, LOW);
      delay(300);
    }
  }
}
