/*
  Example sketch RollDice3.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.

  Neopixel animation is based on Strandtest example by Adafruit.
  http://kjll.cm/arduino-strandtest
*/


// Include the Neopixel, servo and button library
#include <Adafruit_NeoPixel.h>
#include <Adafruit_TiCoServo.h>
#include <Button.h>

// Declare and initialise global GPIO pin constant for Neopixel ring
const byte neoPin = 10;

// Declare and initialise global constant for number of pixels
const byte neoPixels = 24;

// Declare and initialise variable for Neopixel brightness
byte neoBright = 100;

// Create new Neopixel ring object
Adafruit_NeoPixel ring = Adafruit_NeoPixel(neoPixels, neoPin, NEO_GRB);

// Create button object for  GPIO pin 13
Button btnRoll(13);

// Create new servo object
Adafruit_TiCoServo servo; 

void setup() {
  
  // Initialise the ring and turn off pixels
  ring.begin();
  ring.show();

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
    setDice(i);
     delay(1000);
  }
}

void loop() {
  
  // Roll dice
  if(btnRoll.pressed()) {
    
    // Turn up brightness on Neopixel
    ring.setBrightness(neoBright);   
    ring.show(); 

    // Spin Neopixel
    while(!btnRoll.released()){
      rainbowCycle();
    }

    // Turn down brightness
    for(int i = neoBright; i >= 0; i--){
      ring.setBrightness(i);
      ring.show();
      delay(1);
    }

    // Move servo
    upDown();
    setDice(random(1, 7));
  }
}

void upDown() {
  
  // Move servo up and down
  setDice(6);
  delay(600);
  setDice(1);
  delay(600);
}

void setDice(int number){
  
  // Map scale
  int dicePointer = map(number, 1, 6, 20, 140); 

  // Move servo
  servo.write(dicePointer);
}

void rainbowCycle() {
  uint16_t i, j;

  for(j = 0; j < 256; j++) {
    for(i = 0; i < neoPixels; i++) {
      ring.setPixelColor(i, wheel(((i * 256 / neoPixels) + j) & 255));
    }
    ring.show();
  }
}

uint32_t wheel(byte wheelPos) {
  wheelPos = 255 - wheelPos;
  if(wheelPos < 85) {
    return ring.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  if(wheelPos < 170) {
    wheelPos -= 85;
    return ring.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
  wheelPos -= 170;
  return ring.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
}
