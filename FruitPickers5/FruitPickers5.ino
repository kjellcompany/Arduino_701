/*
  Example sketch FruitPickers5.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


// Include the button library
#include <Button.h>

// Create a button object for each GPIO pin in use
Button btnAddAlice(5);
Button btnAddBob(4);
Button btnAddCharlie(3);
Button btnAddDave(2);

// Declare global arrays for names and targets
const String names[] = {"Alice", "Bob", "Charlie", "Dave"};
long fruitsStatus[4];
const long fruitsTarget[] = {1000, 1200, 800, 600};

// Define global variable for basket size
const int basketSize = 50;

void setup() {
  
  // Open serial connection at 115200 Bd.
  Serial.begin(115200);

  // Start buttons
  btnAddAlice.begin();
  btnAddBob.begin();
  btnAddCharlie.begin();
  btnAddDave.begin();
}

void loop() {
  if(btnAddAlice.pressed()){
    updateStatus(basketSize, 0);
  }
  if(btnAddBob.pressed()){
    updateStatus(basketSize, 1);
  }
  if(btnAddCharlie.pressed()){
    updateStatus(basketSize, 2);
  }
  if(btnAddDave.pressed()){
    updateStatus(basketSize, 3);
  }
}

void updateStatus(long amount, int person){
  fruitsStatus[person] = fruitsStatus[person] + amount;

  // Print status
  for(int i = 0; i<=3; i++){
    Serial.print(names[i]);
    Serial.print(" has picked ");
    Serial.print(fruitsStatus[i]);
    Serial.print(" apples, and has ");

    // Check if target is reached
    if(fruitsStatus[i] < fruitsTarget[i]){
      Serial.print(fruitsTarget[i]-fruitsStatus[i]);
    }
    else{
      Serial.print("no");
    }
    
    Serial.println(" apples left to pick");
  }
  Serial.println("--------------------------------------------------------");
}

