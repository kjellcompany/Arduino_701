/*
  Example sketch MathFunction.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  This code is in the public domain.
*/


void setup() {
  
  // Open serial connection at 9600 Bd.
  Serial.begin(9600);
}

void loop() {
  long answer = adder(628, 709);
  Serial.println(answer);
  delay(1000);
}

long adder(long value1, long value2) {
  
  // Add values and return sum
  long sum = value1 + value2;
  return sum;
}

