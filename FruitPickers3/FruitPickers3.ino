/*
  Example sketch FruitPickers3.ino version 7.01.
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

// Declare global variables for total number of apples.
unsigned int fruitsAlice;
unsigned int fruitsBob; 

// Declare global constants for number of apples in baskets.
const int littleBasketSize = 25;
const int bigBasketSize = 40;

// Declare global fruit string
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
  
  // Add little basket to Alice
  if(btnAddLittleBasketAlice.pressed()) {
    fruitsAlice = fruitsAlice + littleBasketSize;
    Serial.print("Alice has picked: ");
    Serial.print(fruitsAlice);
    Serial.println(fruit);
    Serial.print("Bob has picked: ");
    Serial.print(fruitsBob);
    Serial.println(fruit);
    Serial.println("------------------------------");
  }

  // Add little basket to Bob
  if(btnAddLittleBasketBob.pressed()) {
    fruitsBob = fruitsBob + littleBasketSize;
    Serial.print("Alice has picked: ");
    Serial.print(fruitsAlice);
    Serial.println(fruit);
    Serial.print("Bob has picked: ");
    Serial.print(fruitsBob);
    Serial.println(fruit);
    Serial.println("------------------------------");
  }

  // Add big basket to Alice
  if(btnAddBigBasketAlice.pressed()) {
    fruitsAlice = fruitsAlice + bigBasketSize;
    Serial.print("Alice has picked: ");
    Serial.print(fruitsAlice);
    Serial.println(fruit);
    Serial.print("Bob has picked: ");
    Serial.print(fruitsBob);
    Serial.println(fruit);
    Serial.println("------------------------------");
  }  

  // Add big basket to Bob
  if(btnAddBigBasketBob.pressed()) {
    fruitsBob = fruitsBob + bigBasketSize;
    Serial.print("Alice has picked: ");
    Serial.print(fruitsAlice);
    Serial.println(fruit);
    Serial.print("Bob has picked: ");
    Serial.print(fruitsBob);
    Serial.println(fruit);
    Serial.println("------------------------------");
  }
}
