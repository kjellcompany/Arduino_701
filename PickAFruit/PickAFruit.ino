/*
  Example sketch PickAFruit.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


void setup() {
  
  // Open serial connection at 9600 Bd.
  Serial.begin(9600);
}

void loop() {

  // Get random value between 0 and 9
  byte value = random(0,9);
  String pickedFruit;

  switch(value){
    case 0:
      pickedFruit = "banana";
      break;
    case 1:
      pickedFruit = "clementine";
      break;
    case 2:
      pickedFruit = "grape";
      break;
    case 3:
      pickedFruit = "mango";
      break;
    case 4:
      pickedFruit = "pear";
      break;
    default:
      pickedFruit = "pineapple";
      break;
  }

  Serial.print("Have a ");
  Serial.println(pickedFruit);

  delay(1000);
}
