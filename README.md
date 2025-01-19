
# Yuhan68 Piano Notes Library

## Introduction

The **Yuhan68 Piano Notes Library** is designed to simplify working with piano note definitions and functionality, making it easier to manage and reduce clutter in piano-related projects. This library provides utility functions for handling beats, note durations, and octave management, enabling efficient and intuitive interaction for developers.

## Features

- **Set BPM (Beats Per Minute):** Easily define the tempo of your music project.
- **Note Duration Calculations:** Obtain durations for whole, half, quarter, eighth, and sixteenth notes.
- **Octave Control:** Adjust octaves dynamically using button inputs, with safeguards to prevent going beyond the valid range (C0 to C8).
- **Debounce Handling:** Reliable button press detection with built-in debounce logic.

## Code Overview

### Global Variables
- **`beatDuration`:** Calculates the duration of a beat based on the BPM (default 120).

### Functions
1. **Tempo Control**
   - `setBPM(int bpm)`: Safely sets the tempo between 1 BPM and 300 BPM.
   
2. **Note Duration**
   - `whole()`: Returns the duration of a whole note.
   - `half()`: Returns the duration of a half note.
   - `quarter()`: Returns the duration of a quarter note.
   - `eighth()`: Returns the duration of an eighth note.
   - `sixteenth()`: Returns the duration of a sixteenth note.
   
3. **Octave Control**
   - `octave_down(int button)`: Decreases the octave by one (min: C0).
   - `octave_up(int button)`: Increases the octave by one (max: C8).

### Safeguards
- Button debounce mechanism to avoid repeated triggers.
- Minimum and maximum BPM and octave limits for robust functionality.

## Author
This library is written and maintained by **Yuhan Cruz**.

## License
This project is licensed under the BSD license. All accompanying text must be included in any redistribution.

---

For more details, explore the source code or documentation. Contributions and feedback are welcome!
```
