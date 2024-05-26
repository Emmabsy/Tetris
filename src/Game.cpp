#include "Game.hpp"
#include "Game.hpp"

Game::Game() : timer(0), delay(0.5f), gameState(GameState::Playing)
                                          
{
    srand(static_cast<unsigned int>(time(0)));
    if (!backgroundTexture.loadFromFile("/Users/admin/Documents/HUB/Gaming/Tetris/assets/background.png"))
    {
        // Handle loading error
    }
    // Calculate window size based on board size and tile size
    int windowWidth = BOARD_WIDTH * BLOCK_SIZE;
    int windowHeight = BOARD_HEIGHT * BLOCK_SIZE;
    window.create(sf::VideoMode(windowWidth, windowHeight), "Tetris");
    backgroundSprite.setTexture(backgroundTexture);
    font.loadFromFile("path/to/font.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
}

void Game::run()
{
    while (window.isOpen())
    {
        handleInput();
        if (gameState == GameState::Playing)
        {
            update();
        }
        render();
    }
}

void Game::handleInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (gameState == GameState::Playing)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    currentPiece.rotate();
                    if (currentPiece.collides(board))
                    {
                        currentPiece.rotate();
                        currentPiece.rotate();
                        currentPiece.rotate();
                    }
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    currentPiece.move(-1, 0);
                    if (currentPiece.collides(board))
                    {
                        currentPiece.move(1, 0);
                    }
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    currentPiece.move(1, 0);
                    if (currentPiece.collides(board))
                    {
                        currentPiece.move(-1, 0);
                    }
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    currentPiece.move(0, 1);
                    if (currentPiece.collides(board))
                    {
                        currentPiece.move(0, -1);
                        board.placePiece(currentPiece.getX(), currentPiece.getY(), currentPiece.getShape());
                        currentPiece.reset();
                        if (currentPiece.collides(board))
                        {
                            gameState = GameState::GameOver;
                        }
                    }
                }
                else if (event.key.code == sf::Keyboard::P)
                {
                    gameState = GameState::Paused;
                }
            }
            else if (gameState == GameState::Paused)
            {
                if (event.key.code == sf::Keyboard::P)
                {
                    gameState = GameState::Playing;
                }
                else if (event.key.code == sf::Keyboard::R)
                {
                    resetGame();
                }
            }
            else if (gameState == GameState::GameOver)
            {
                if (event.key.code == sf::Keyboard::R)
                {
                    resetGame();
                }
            }
        }
    }
}

void Game::update()
{
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    if (timer > delay)
    {
        currentPiece.move(0, 1);
        if (currentPiece.collides(board))
        {
            currentPiece.move(0, -1);
            board.placePiece(currentPiece.getX(), currentPiece.getY(), currentPiece.getShape());
            currentPiece.reset();
            if (currentPiece.collides(board))
            {
                gameState = GameState::GameOver;
            }
        }
        timer = 0;
    }
}

void Game::render()
{
    window.clear();
    window.draw(backgroundSprite);
    board.draw(window);
    if (gameState == GameState::Playing || gameState == GameState::Paused)
    {
        currentPiece.draw(window);
    }

    if (gameState == GameState::Paused)
    {
        text.setString("Paused\nPress P to resume\nPress R to restart");
        text.setPosition(50, 250);
        window.draw(text);
    }
    else if (gameState == GameState::GameOver)
    {
        text.setString("Game Over\nPress R to restart");
        text.setPosition(50, 250);
        window.draw(text);
    }

    window.display();
}

void Game::resetGame()
{
    board.clear();
    currentPiece.reset();
    gameState = GameState::Playing;
    timer = 0;
}