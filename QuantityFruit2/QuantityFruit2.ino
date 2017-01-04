/*
  Example sketch QuantityFruit2.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/



// Declare global constants for quantities
const int quantityApples = 1337;
const int quantityBananas = 42;

void setup() {
  
  // Open serial connection at 9600 Bd.
  Serial.begin(9600);
}

void loop() {
  
  // Compare amounts of apples and bananas and print info
  if(quantityApples > quantityBananas) {
    Serial.println("We've got more apples than bananas.");
  }
  else if(quantityApples < quantityBananas) {
    Serial.println("We’ve got less apples than bananas.");
  }
  else {
    Serial.println("We've got the same amount of apples and bananas.");
  }

  delay(1000);
}
