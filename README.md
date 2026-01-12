# Student simulator - course project 11

This is a console-based simulation game developed as a course project for "Introduction to Programming" at FMI, Sofia
University (2025/2026).

## Description

The game simulates the life of a student who must survive 45 days during an exam session. The goal is to pass 5 exams
while managing money, energy, and mental health ("psychics"). If any vital statistic drops to zero, the game ends.

## Game features

- **Dynamic Statistics:** Tracks Money, Energy, Psychics, and Knowledge.
- **Random Events:** Daily events and action-specific outcomes affecting stats.
- **Exam System:** Realistic success formula based on knowledge and luck.
- **Save/Load:** Progress can be saved to a file and reloaded.
- **Difficulty Levels:** Easy, Normal, and Hard modes.

## How to compile and run

The project consists of a single source file. It does not use external libraries (other than standard streams).

1. Create a new C++ Console Project.
2. Add main.cpp to source files.
3. Build and run(Ctrl + F5).

## Technologies Used

- **C++ Core Language**
- **`<fstream>`**: For file operations (saving and loading game state).
- **`<random>`**: Utilized for high-quality random number generation (Mersenne Twister algorithm) to ensure fair and
  unpredictable game events.
- **`<limits>`**: Used for robust input validation and buffer clearing to prevent infinite loops on invalid input.
