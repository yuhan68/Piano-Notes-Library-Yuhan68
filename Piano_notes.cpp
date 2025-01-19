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

// Function to set BPM
void setBPM(int bpm) {
    if (bpm < 1) bpm = 1;       // Minimum BPM safeguard
    if (bpm > 550) bpm = 550;   // Maximum BPM safeguard
    beatDuration = 60000 / bpm; // Milliseconds per beat (quarter note)
}

void BPM_down(int button) {
    static unsigned long lastPressTime = 0;  // Tracks the last button press time
    static unsigned long pressStartTime = 0; // Tracks when the button was first pressed
    const unsigned long debounceDelay = 200; // Delay in milliseconds for debounce

    if (digitalRead(button) == HIGH) { // Check if the button is pressed
        unsigned long currentTime = millis(); // Get the current time

        if (pressStartTime == 0) pressStartTime = currentTime; // Set press start time if button is first pressed

        unsigned long pressDuration = currentTime - pressStartTime; // Calculate how long the button has been held

        int decrementRate = 1 + (pressDuration / 1000); // Faster decrement as button is held longer

        if (currentTime - lastPressTime > debounceDelay / decrementRate) { // Adjust debounce delay dynamically
            if (beatDuration > 0) beatDuration--; // Decrease BPM, ensure it doesn't go below 0
            Serial.print("Your BPM is now: "); // Print the updated BPM
            Serial.println(beatDuration);
            lastPressTime = currentTime; // Update the last press time
        }
    } else {
        pressStartTime = 0; // Reset press start time when button is released
    }
}

void BPM_up(int button) {
    static unsigned long lastPressTime = 0;  // Tracks the last button press time
    static unsigned long pressStartTime = 0; // Tracks when the button was first pressed
    const unsigned long debounceDelay = 200; // Delay in milliseconds for debounce

    if (digitalRead(button) == HIGH) { // Check if the button is pressed
        unsigned long currentTime = millis(); // Get the current time

        if (pressStartTime == 0) pressStartTime = currentTime; // Set press start time if button is first pressed

        unsigned long pressDuration = currentTime - pressStartTime; // Calculate how long the button has been held

        int incrementRate = 1 + (pressDuration / 1000); // Faster increment as button is held longer

        if (currentTime - lastPressTime > debounceDelay / incrementRate) { // Adjust debounce delay dynamically
            if (beatDuration < 550) beatDuration++; // Increase BPM, ensure it doesn't go above 550
            Serial.print("Your BPM is now: "); // Print the updated BPM
            Serial.println(beatDuration);
            lastPressTime = currentTime; // Update the last press time
        }
    } else {
        pressStartTime = 0; // Reset press start time when button is released
    }
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
