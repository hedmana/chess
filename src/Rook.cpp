#include "Rook.hpp"

Rook::Rook(int x, int y, int width, int height, int color)
    : Piece(x, y, width, height, color)
{
    if (color_ == WHITE)
        texturePath_ = "assets/sprites/rook_w.png";
    else
        texturePath_ = "assets/sprites/rook_b.png";

    texture_.loadFromFile(texturePath_);
    sprite_.setTexture(texture_);
    sprite_.setScale(width_ / texture_.getSize().x, height_ / texture_.getSize().y);
    sprite_.setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);
    sprite_.setPosition(x_, y_);
}

Rook::~Rook()
{
}