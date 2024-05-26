#pragma once
#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "Piece.hpp"

class Game
{
public:
    Game();
    void run();

private:
    void handleInput();
    void update();
    void render();

    sf::RenderWindow window;
    Board board;
    Piece currentPiece;
    sf::Clock clock;
    float timer;
    float delay;
};
