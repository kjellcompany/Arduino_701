/*
  Example sketch NamePrinter.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


// Define global name array
const String names[] = {"Alice", "Bob", "Charlie", "Dave"};
  
void setup() {
  
  // Open serial connection at 9600 Bd.
  Serial.begin(9600);
}

void loop() {
  
  // Print all names in names.
  for(int i = 0; i <= 3; i++){
    Serial.println(names[i]);
  }

  // Print all names in names[] in reverse order.
  for(int i = 3; i >= 0; i--){
    Serial.println(names[i]);
  }
  
  delay(1000);
}


