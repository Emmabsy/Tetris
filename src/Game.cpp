#include "Game.hpp"

Game::Game() : window(sf::VideoMode(300, 600), "Tetris"), timer(0), delay(0.5f)
{
    srand(static_cast<unsigned int>(time(0)));
}

void Game::run()
{
    while (window.isOpen())
    {
        handleInput();
        update();
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
            if (event.key.code == sf::Keyboard::Up)
            {
                currentPiece.rotate();
                if (currentPiece.collides(board))
                {
                    // Undo rotation if collides
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
                    // Undo move if collides
                    currentPiece.move(1, 0);
                }
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                currentPiece.move(1, 0);
                if (currentPiece.collides(board))
                {
                    // Undo move if collides
                    currentPiece.move(-1, 0);
                }
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                currentPiece.move(0, 1);
                if (currentPiece.collides(board))
                {
                    // Undo move if collides
                    currentPiece.move(0, -1);
                    board.placePiece(currentPiece.getX(), currentPiece.getY(), currentPiece.getShape());
                    currentPiece.reset();
                    if (currentPiece.collides(board))
                    {
                        // Game over condition
                        window.close();
                    }
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
                // Game over condition
                window.close();
            }
        }
        timer = 0;
    }
}

void Game::render()
{
    window.clear(sf::Color::White);
    board.draw(window);
    currentPiece.draw(window);
    window.display();
}
