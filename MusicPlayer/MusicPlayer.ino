/*
  Example sketch MusicPlayer.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  Based on Tone Tutorial from http://www.arduino.cc/en/Tutorial/Tone.

  This code is in the public domain.
*/



#include "pitches.h"
#include "melody.h"

// Declare global pin constant for buzzer
const byte buzzerPin = 10;

void setup() {

}

void loop() {
  playTone(melody, noteDurations, sizeof(melody)/sizeof(int));
}

void playTone(int melody[], int noteDurations[],int lengths) {
  
  // Iterate over the notes of the melody:
  for (int thisNote = 0; thisNote <  lengths; thisNote++) {

    // To calculate the note duration, take one second divided by the note 
    // type e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    // To distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stop the tone playing
    noTone(buzzerPin);
  } 
}

