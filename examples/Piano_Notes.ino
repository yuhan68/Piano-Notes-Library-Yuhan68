/*************************************************** 
  This is an example for the Piano_notes library


  Two buttons are wired to control a single buzzer, 3 pins
  are required to interface
  

  Written by Yuhan Cruz
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// Connect one button to pin 12 and another to pin 13, and then wire the rest accordingly with resistors and wires
// Connect the buzzer to pin 7 and wire the rest accordingly
// Set the BPM to a number, e.g. 120, in the setBPM() funciton to the pace desired


#include "Piano_notes.h"

//Defining pins
int button1 = 12;
int button2 = 13;  // Pin connected to the button
int buzzer = 7;  // Pin connected to the buzzer

void setup() {
  // put your setup code here, to run once:
  setBPM(120);   //Setting the BPM

  //INPUTS/OUTPUTS
  pinMode(buzzer, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if(digitalRead(button1) == HIGH){
    tone(buzzer, f3);
    delay(whole());//play the note for the duration of a whole note at bpm set earlier
    tone(buzzer, a3);
    delay(eighth());//play the note for the duration of a eighth note at bpm set earlier
  }
  else if(digitalRead(button2) == HIGH){
    tone(buzzer, d4);
  }
  else{
    noTone(buzzer);//end the sound
  }  
}

