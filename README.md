# Piano Notes Library

## Overview

The Piano Notes Library is a utility designed to simplify the work of defining piano notes and related functionalities in music projects. It streamlines the definition of note frequencies, handling beats, tempo changes (BPM), note durations, and octave shifts, making it easier to integrate music-related logic into projects.

## Features

- **Defined Notes**:
  - All notes from `A0` to `C8` are defined in frequencies for buzzers to play the associated note.
 
- **Dynamic BPM Adjustment**: 
  - Increase or decrease BPM interactively with a button press.
  - Gradual rate changes depending on how long the button is pressed.

- **Note Duration Calculations**: 
  - Automatically compute note durations for whole, half, quarter, eighth, and sixteenth notes based on the current BPM.

- **Octave Control**:
  - Adjust the octave up or down interactively within a range of (`A0` to `C8`).

- **Debounce Handling**: 
  - Integrated debounce logic ensures reliable button press detection without unintentional repeats.

## Functions

### BPM Management
- **`void setBPM(int bpm)`**: Sets the beats per minute, with limits between 1 and 550 BPM.
- **`void BPM_down(int button)`**: Decreases BPM when a button is pressed, with a dynamic decrement rate.
- **`void BPM_up(int button)`**: Increases BPM when a button is pressed, with a dynamic increment rate.

### Note Durations
- **`int whole()`**: Returns the duration of a whole note in milliseconds.
- **`int half()`**: Returns the duration of a half note in milliseconds.
- **`int quarter()`**: Returns the duration of a quarter note in milliseconds.
- **`int eighth()`**: Returns the duration of an eighth note in milliseconds.
- **`int sixteenth()`**: Returns the duration of a sixteenth note in milliseconds.

### Octave Adjustment
- **`void octave_down(int button)`**: Decreases the current octave, ensuring it does not go below `C0`.
- **`void octave_up(int button)`**: Increases the current octave, ensuring it does not exceed `C8`.

## Example Usage

```cpp
#include "Piano_notes.h"

void setup() {
    Serial.begin(9600);
    setBPM(120); // Set initial BPM to 120
}

void loop() {
    // Example button logic for BPM or octave adjustment
    BPM_up(2);   // Increment BPM using the button connected to pin 2
    BPM_down(3); // Decrement BPM using the button connected to pin 3
    octave_up(4); // Shift octave up using the button connected to pin 4
    octave_down(5); // Shift octave down using the button connected to pin 5
}
