# Changelog

All notable changes to this project will be documented in this file.

## [1.1.0] - 2025-01-18
### Added
- New `BPM_up` and `BPM_down` functions to handle BPM adjustments.
- Dynamic BPM change logic with long-press functionality.

### Fixed
- Corrected debounce timing logic for button presses.
- BPM safeguard changed to 550 BPM for more flexibility. 

## [1.0.0] - 2025-01-18
### Initial Release
The first stable release of the Piano Notes Library, offering foundational functionality for handling piano notes, BPM adjustments, and note durations in music-related projects.

#### Features
  - **Note Definitions**:
  - Defined all notes from a0 to c8.

  - **BPM Management**:
  - `setBPM(int bpm)`: Set beats per minute with safeguards between 1 and 300 BPM.
  - Default BPM set to 120.

- **Note Duration Calculations**:
  - `whole()`: Returns the duration of a whole note based on the current BPM.
  - `half()`: Calculates the duration of a half note.
  - `quarter()`: Provides the duration of a quarter note.
  - `eighth()`: Calculates the duration of an eighth note.
  - `sixteenth()`: Returns the duration of a sixteenth note.

- **Global State Variables**:
  - `beatDuration`: Automatically updated whenever BPM changes, ensuring all note duration calculations remain synchronized.
  - Default beat duration set for 120 BPM (500ms per quarter note).
