/*
  Example sketch FruitPickers2.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/



// Declare global variables for total number of apples.
unsigned int fruitsAlice;
unsigned int fruitsBob; 

// Declare global constants for number of apples in baskets.
const int littleBasketSize = 25;
const int bigBasketSize = 40;

// Declare global variables for number of baskets
int littleBasketAlice = 20;
int bigBasketAlice = 15;
int littleBasketBob = 17;
int bigBasketBob = 17;

// Declare global fruit String
String fruit = " apples";

void setup() {
  
  // Open serial connection at 9600 Bd.
  Serial.begin(9600);
}

void loop() {
  
  // Count total number of apples.
  fruitsAlice = littleBasketAlice * littleBasketSize + 
    bigBasketAlice * bigBasketSize;
  fruitsBob = littleBasketBob * littleBasketSize + 
    bigBasketBob * bigBasketSize;

  // Print number of apples.
  Serial.print("Alice has picked: ");
  Serial.print(fruitsAlice);
  Serial.println(fruit);
  Serial.print("Bob has picked: ");
  Serial.print(fruitsBob);
  Serial.println(fruit);

  // Add delay
  delay(5000);
}
