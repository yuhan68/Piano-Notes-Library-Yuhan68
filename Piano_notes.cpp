/*!
 * @file Piano_notes.cpp
 *
 * @mainpage Yuhan68 Piano_Notes Library
 *
 * @section intro_sec Introduction
 *
 * This is a library for defining piano notes, adding easier functionality
 * , and reducing clutter for people reading my piano project. 
 * 
 *

 * @section author Author
 *
 * Written by Yuhan Cruz
 * Updated by Yuhan Cruz
 *
 * @section license License
 *
 * BSD license, all text above must be included in any redistribution
 */

#include "Piano_notes.h"

// Global variable to hold beat duration
static int beatDuration = 60000 / 120; // Default BPM = 120

// Function to set BPM
void setBPM(int bpm) {
    if (bpm < 1) bpm = 1;       // Minimum BPM safeguard
    if (bpm > 300) bpm = 300;   // Maximum BPM safeguard
    beatDuration = 60000 / bpm; // Milliseconds per beat (quarter note)
}

// Duration functions
int whole() {
    return 4 * beatDuration;
}

int half() {
    return 2 * beatDuration;
}

int quarter() {
    return beatDuration;
}

int eighth() {
    return beatDuration / 2;
}

int sixteenth() {
    return beatDuration / 4;
}

//Ocatve up and down function
int O = 3;

void octave_down(int button) {
    static unsigned long lastPressTime = 0; // To track the last button press time
    const unsigned long debounceDelay = 200; // Delay in milliseconds

    if (digitalRead(button) == HIGH) {
        unsigned long currentTime = millis();
        if (currentTime - lastPressTime > debounceDelay) {
            if (O > 0) { // Prevent going below C0
                O--; // Decrease the octave
                Serial.print("Your octave is now: ");
                Serial.println(O);
            }
            lastPressTime = currentTime; // Update the last press time
        }
    }
}

void octave_up(int button) {
    static unsigned long lastPressTime = 0; // To track the last button press time
    const unsigned long debounceDelay = 200; // Delay in milliseconds

    if (digitalRead(button) == HIGH) {
        unsigned long currentTime = millis();
        if (currentTime - lastPressTime > debounceDelay) {
            if (O < 8) { // Prevent going above C8
                O++; // Increase the octave
                Serial.print("Your octave is now: ");
                Serial.println(O);
            }
            lastPressTime = currentTime; // Update the last press time
        }
    }
}
