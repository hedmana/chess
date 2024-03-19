#include "Piece.hpp"

Piece::Piece(int x, int y, int width, int height, int color)
    : x_(x), y_(y), width_(width), height_(height), color_(color)
{
    selected_ = false;
    captured_ = false;
    base_x_ = x_;
    base_y_ = y_;
}

Piece::~Piece()
{
}

sf::Sprite& Piece::getSprite()
{
    return(sprite_);
}

std::pair<int, int> Piece::getCoordinates()
{
    return(std::make_pair(x_, y_));
}

std::pair<int, int> Piece::getBaseCoordinates()
{
    return(std::make_pair(base_x_, base_y_));
}

int Piece::getColor()
{
    return(color_);
}

void Piece::setCoordinates(int x, int y)
{
    x_ = x;
    y_ = y;
    sprite_.setPosition(x_, y_);
}

void Piece::setBaseCoordinates(int x, int y)
{
    base_x_ = x;
    base_y_ = y;
}

void Piece::setSelected(bool selected)
{
    selected_ = selected;
}

bool Piece::isSelected()
{
    return(selected_);
}

bool Piece::isCaptured()
{
    return(captured_);
}

void Piece::setCaptured(bool captured)
{
    std::cout << "Piece captured!" << std::endl;
    captured_ = captured;
}