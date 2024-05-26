#include "Board.hpp"
#include "Constants.hpp"

Board::Board() : gameOver(false)
{
    clear();
    for (int i = 0; i < BOARD_HEIGHT; ++i)
    {
        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            blocks[i][j].setSize(sf::Vector2f(30, 30));
            blocks[i][j].setOutlineThickness(1);
            blocks[i][j].setOutlineColor(sf::Color::Black);
            blocks[i][j].setPosition(j * 30, i * 30);
        }
    }
}

void Board::clear()
{
    for (int i = 0; i < BOARD_HEIGHT; ++i)
    {
        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            board[i][j] = 0;
        }
    }
}

bool Board::isValidMove(int x, int y, const int piece[4][4]) const
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (piece[i][j] != 0)
            {
                int newX = x + j;
                int newY = y + i;
                if (newX < 0 || newX >= BOARD_WIDTH || newY >= BOARD_HEIGHT || (newY >= 0 && board[newY][newX] != 0))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void Board::placePiece(int x, int y, const int piece[4][4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (piece[i][j] != 0)
            {
                board[y + i][x + j] = piece[i][j]; // Place the unique piece value on the board
            }
        }
    }
    checkLines();
}

void Board::checkLines()
{
    for (int i = 0; i < BOARD_HEIGHT; ++i)
    {
        bool lineFull = true;
        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            if (board[i][j] == 0)
            {
                lineFull = false;
                break;
            }
        }
        if (lineFull)
        {
            for (int k = i; k > 0; --k)
            {
                for (int j = 0; j < BOARD_WIDTH; ++j)
                {
                    board[k][j] = board[k - 1][j];
                }
            }
            for (int j = 0; j < BOARD_WIDTH; ++j)
            {
                board[0][j] = 0;
            }
        }
    }
}

bool Board::isGameOver() const
{
    return gameOver;
}
void Board::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < BOARD_HEIGHT; ++i)
    {
        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            // Set color based on block value
            sf::Color color;
            switch (board[i][j])
            {
            case 1: // I shape
                color = sf::Color::Green;
                break;
            case 2: // J shape
                color = sf::Color::Blue;
                break;
            case 3: // L shape
                color = sf::Color::Red;
                break;
            case 4: // O shape
                color = sf::Color::Yellow;
                break;
            case 5: // S shape
                color = sf::Color::Magenta;
                break;
            case 6: // T shape
                color = sf::Color::Cyan;
                break;
            case 7: // Z shape
                color = sf::Color::White;
                break;
            default: // Empty cell
                color = sf::Color::Transparent;
                break;
            }
            blocks[i][j].setFillColor(color);
            window.draw(blocks[i][j]);
        }
    }
}
