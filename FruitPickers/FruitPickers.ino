/*
  Example sketch FruitPickers.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/



// Declare global variables for total number of fruits.
int fruitsAlice;
int fruitsBob;

// Declare global variables for number of apples in baskets.
int littleBasketSize = 25;
int bigBasketSize = 40;

// Declare global variables for number of baskets
int littleBasketAlice = 20;
int bigBasketAlice = 15;
int littleBasketBob = 17;
int bigBasketBob = 17;

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
  Serial.println(" apples");
  Serial.print("Bob has picked: ");
  Serial.print(fruitsBob);
  Serial.println(" apples");

  // Add delay
  delay(5000);
}
