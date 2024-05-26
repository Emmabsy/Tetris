#pragma once
#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "Piece.hpp"

enum class GameState
{
    Playing,
    Paused,
    GameOver
};

class Game
{
public:
    Game();
    void run();

private:
    void handleInput();
    void update();
    void render();
    void resetGame();

    sf::RenderWindow window;
    Board board;
    Piece currentPiece;
    sf::Clock clock;
    float timer;
    float delay;

    GameState gameState;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    
    sf::Font font;
    sf::Text text;
};
