# IC_CP_03
C++ 2048 Game – Task 3 assigned by Interncred

## 2048 Game (C++)

This repository contains a console-based implementation of the 2048 game in C++  
as part of Task 3 assigned by Interncred during the internship.

The game is played on a 4x4 grid. Two tiles are randomly initialized at the start,  
and the player moves tiles using Up, Down, Left, and Right controls. Tiles of the  
same value merge into one tile with double the value.

## Features
- 4x4 game board with random tile initialization
- Up, Down, Left, Right controls
- Merge tiles of the same value
- Score tracking when tiles merge
- Game over when no moves are left
- Win condition when a 2048 tile is created

## How It Works
1. Two tiles (2 or 4) are added randomly at the start.
2. Player uses W/A/S/D to move tiles.
3. Tiles merge if adjacent tiles have the same value.
4. After each valid move, a new tile is added randomly.
5. The game ends if no moves are possible.

## Concepts Covered
- Arrays and 2D arrays
- Loops and conditionals
- Functions and modular programming
- Random number generation
- Console-based game mechanics

## How to Run
1. Compile the program:
   ```bash
   g++ -o game 2048.cpp

2. Run the program:
./game

3. Use W/A/S/D keys to move tiles.

## Author

Priya Malhotra
