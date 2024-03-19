#include "Knight.hpp"

Knight::Knight(int x, int y, int width, int height, int color)
    : Piece(x, y, width, height, color)
{
    if (color == WHITE)
    {
        texturePath_ = "assets/sprites/knight_w.png";
    }
    else
    {
        texturePath_ = "assets/sprites/knight_b.png";
    }
    
    texture_.loadFromFile(texturePath_);
    sprite_.setTexture(texture_);
    sprite_.setScale(width_ / texture_.getSize().x, height_ / texture_.getSize().y);
    sprite_.setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);
    sprite_.setPosition(x_, y_);
}

Knight::~Knight()
{
}