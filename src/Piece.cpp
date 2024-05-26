#include "Piece.hpp"
#include "Board.hpp"

Piece::Piece()
{
    generateShapes();
    reset();
}

void Piece::generateShapes()
{
    // Define the 7 Tetris shapes with unique values for each shape
    int tShapes[7][4][4] = {
        // I
        {{0, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 1, 0, 0}},

        // J
        {{0, 0, 2, 0},
         {0, 0, 2, 0},
         {0, 2, 2, 0},
         {0, 0, 0, 0}},

        // L
        {{0, 3, 0, 0},
         {0, 3, 0, 0},
         {0, 3, 3, 0},
         {0, 0, 0, 0}},

        // O
        {{0, 0, 0, 0},
         {0, 4, 4, 0},
         {0, 4, 4, 0},
         {0, 0, 0, 0}},

        // S
        {{0, 0, 0, 0},
         {0, 5, 5, 0},
         {5, 5, 0, 0},
         {0, 0, 0, 0}},

        // T
        {{0, 0, 0, 0},
         {0, 6, 0, 0},
         {6, 6, 6, 0},
         {0, 0, 0, 0}},

        // Z
        {{0, 0, 0, 0},
         {7, 7, 0, 0},
         {0, 7, 7, 0},
         {0, 0, 0, 0}}};
    for (int i = 0; i < 7; ++i)
    {
        copyShape(shapes[i], tShapes[i]);
    }
}

void Piece::copyShape(int destination[4][4], const int source[4][4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            destination[i][j] = source[i][j];
        }
    }
}

void Piece::reset()
{
    currentShape = rand() % 7;
    copyShape(shape, shapes[currentShape]);
    x = BOARD_WIDTH / 2 - 2;
    y = 0;
}

void Piece::move(int dx, int dy)
{
    x += dx;
    y += dy;
}

void Piece::rotate()
{
    int temp[4][4];
    copyShape(temp, shape);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            shape[i][j] = temp[3 - j][i];
        }
    }
}

bool Piece::collides(const Board &board) const
{
    return !board.isValidMove(x, y, shape);
}

void Piece::draw(sf::RenderWindow &window)
{
    sf::RectangleShape block(sf::Vector2f(30, 30));
    block.setOutlineThickness(1);
    block.setOutlineColor(sf::Color::Black);

    // Define colors for each shape
    sf::Color colors[7] = {
        sf::Color::Green,   // I
        sf::Color::Blue,    // J
        sf::Color::Red,     // L
        sf::Color::Yellow,  // O
        sf::Color::Magenta, // S
        sf::Color::Cyan,    // T
        sf::Color::White    // Z
    };

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (shape[i][j] != 0)
            {
                block.setFillColor(colors[currentShape]); // Set color based on currentShape
                block.setPosition((x + j) * 30, (y + i) * 30);
                window.draw(block);
            }
        }
    }
}

int Piece::getX() const
{
    return x;
}

int Piece::getY() const
{
    return y;
}

const int (*Piece::getShape() const)[4]
{
    return shape;
}
