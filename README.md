# TwentyFour Game

## Overview
"TwentyFour" is a C-language based mathematical puzzle game. The objective is to use four numbers, each exactly once, and combine them with basic arithmetic operations (+, -, *, /) to reach the value twenty-four.

## Features
- Two game modes: Easy and Hard.
- Debug mode for generating all possible solutions.
- Random puzzle generation in Hard mode.
- Structured and well-commented C code.

## Structs
- `struct hand`: Represents a set of four numbers for the puzzle.
- `struct PossibleSolution`: Stores possible combinations of sets of four numbers that equal 24.

## Calculation Functions
- `AddFunction`, `SubtractFunction`, `DivideFunction`, `MultiplyFunction`: Perform respective arithmetic operations.
- `GetOperators`: Determines the operation to perform based on the input operator.
- `CheckOperators`: Checks if the input character is a valid arithmetic operator.

## Randomizer Functions
- `ProblemSelector`: Randomly selects a problem set for Hard mode.
- `RowSelector`: Randomly selects a row for the Easy mode.

## Utility Function
- `display_usage`: Displays the introductory message and instructions.

## Data Functions
- `GetDebugData`: Generates all possible solutions for Debug mode.
- `GetData`: Stores all possible solutions for Hard mode in a struct.
- `RunData`: Prepares data for Hard mode by finding all possible combinations.

## Game and Main Functions
- `runGame`: Main function for Hard mode.
- `RunEasyGame`: Main function for Easy mode.
- `main`: Entry point, handles game mode selection, and loop for replaying the game.

## Compilation and Execution
To compile and run the game:
```bash
gcc twentyfour_game.c -o twentyfour_game
./twentyfour_game
