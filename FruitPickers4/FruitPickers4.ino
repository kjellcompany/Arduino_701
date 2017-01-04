/*
  Example sketch FruitPickers4.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


// Include the button library
#include <Button.h>

// Create a button object for each GPIO pin in use
Button btnAddLittleBasketAlice(5);
Button btnAddLittleBasketBob(4);
Button btnAddBigBasketAlice(3);
Button btnAddBigBasketBob(2);

// Define global variables for total number of apples.
unsigned int fruitsAlice;
unsigned int fruitsBob; 

// Define global constants for number of apples in baskets.
const int littleBasketSize = 25;
const int bigBasketSize = 40;

// Define global fruit string
String fruit = " apples";

void setup() {
  
  // Open serial connection at 9600 Bd.
  Serial.begin(9600);

  // Start buttons
  btnAddLittleBasketAlice.begin();
  btnAddLittleBasketBob.begin();
  btnAddBigBasketAlice.begin();
  btnAddBigBasketBob.begin();
}

void loop() {
  if(btnAddLittleBasketAlice.pressed()){
    updateStatus(littleBasketSize, 0);
  }
  if(btnAddLittleBasketBob.pressed()){
    updateStatus(0, littleBasketSize);
  }
  if(btnAddBigBasketAlice.pressed()){
    updateStatus(bigBasketSize, 0);
  }
  if(btnAddBigBasketBob.pressed()){
    updateStatus(0, bigBasketSize);
  }
}

void updateStatus(int addAlice, int addBob) {
  fruitsAlice = fruitsAlice + addAlice;
  fruitsBob = fruitsBob + addBob;
  Serial.print("Alice has picked: ");
  Serial.print(fruitsAlice);
  Serial.println(fruit);
  Serial.print("Bob has picked: ");
  Serial.print(fruitsBob);
  Serial.println(fruit);
  Serial.println("------------------------------");
}
