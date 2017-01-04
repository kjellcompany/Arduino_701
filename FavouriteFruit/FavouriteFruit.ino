/*
  Example sketch BlinkLed.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


// Declare global constants
const boolean likeApples = true;
const boolean likeBananas = true;

void setup() {
  
  // Open serial connection at 9600 Bd.
  Serial.begin(9600);
}

void loop() {
  
  // Print what kind of fruits you like
  if(likeApples == true && likeBananas == false){
    Serial.println("Have an apple!");
  }
  else if(likeApples == false && likeBananas == true){
    Serial.println("Have a banana!");
  }
  else if(likeApples == true && likeBananas == true){
    Serial.println("Have some fruit salad!");
  }
  else{
    Serial.println("You don't like fruits, right?");
  }

  delay(1000);
}
