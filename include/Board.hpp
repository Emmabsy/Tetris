#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Board
{
public:
    Board();
    void clear();
    bool isValidMove(int x, int y, const int piece[4][4]) const;
    void placePiece(int x, int y, const int piece[4][4]);
    void checkLines();
    bool isGameOver() const;
    void draw(sf::RenderWindow &window);

private:
    int board[BOARD_HEIGHT][BOARD_WIDTH];
    sf::RectangleShape blocks[BOARD_HEIGHT][BOARD_WIDTH];
    bool gameOver;
};
