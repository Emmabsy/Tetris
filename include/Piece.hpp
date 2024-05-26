#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Board;

class Piece
{
public:
    Piece();
    void reset();
    void move(int dx, int dy);
    void rotate();
    bool collides(const Board &board) const;
    void draw(sf::RenderWindow &window);

    int getX() const;
    int getY() const;
    const int (*getShape() const)[4];

private:
    void generateShapes();
    void copyShape(int destination[4][4], const int source[4][4]);

    int shapes[7][4][4];
    int shape[4][4];
    int currentShape;
    int x, y;
};
