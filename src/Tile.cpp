#include "Tile.hpp"

Tile::Tile(int x, int y, int width, int height, int color) 
    : x_(x), y_(y), width_(width), height_(height), color_(color)
{
    occupied_ = false;

    sprite_ = sf::RectangleShape(sf::Vector2f(width_, height_));
    sprite_.setPosition(x_, y_);
    
    if (color_ == WHITE)
        sprite_.setFillColor(sf::Color(255, 255, 255));
    else if (color_ == BLACK)
        sprite_.setFillColor(sf::Color(50, 50, 50));
}

Tile::~Tile()
{
}

int Tile::getColor() const
{
    return(color_);
}

sf::RectangleShape Tile::getSprite() const
{
    return(sprite_);
}

std::pair<int, int> Tile::getPosition()
{
    return(std::make_pair(x_, y_));
}

bool Tile::isOccupied() const
{
    return(occupied_);
}

void Tile::setOccupied(bool occupied)
{
    occupied_ = occupied;
}