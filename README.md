# Tetris Game

This is a simple Tetris game implemented in C++ using the SFML library. The game includes features such as different Tetris shapes, a background texture, and a single texture for the blocks.

## Features

- Seven different Tetris shapes (I, J, L, O, S, T, Z)
- Textured blocks and background
- Game states: Playing, Paused, Game Over
- Basic controls: move left, move right, rotate, drop, pause, and reset

## Controls

- **Left Arrow**: Move piece left
- **Right Arrow**: Move piece right
- **Up Arrow**: Rotate piece
- **Down Arrow**: Drop piece faster
- **P**: Pause/Unpause the game
- **R**: Reset the game

## Installation

### Prerequisites

- C++ compiler (e.g., g++, clang++)
- SFML library (version 2.5.1 or higher)

### Setting Up SFML

Make sure you have SFML installed on your system. You can download it from the [SFML website](https://www.sfml-dev.org/download.php).

### Building the Project

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/tetris-game.git
    cd tetris-game
    ```

2. Create a `resources` folder inside the project directory and add your `block.png` and `background.png` files to it.

3. Compile the project:
    ```bash
    g++ -std=c++11 -o tetris main.cpp Game.cpp Board.cpp Piece.cpp -lsfml-graphics -lsfml-window -lsfml-system
    ```

4. Run the executable:
    ```bash
    ./tetris
    ```

## Project Structure

