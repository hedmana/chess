#ifndef __PIECE_H__
#define __PIECE_H__

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "Enums.hpp"

class Piece
{
protected:
    int x_;
    int y_;
    int base_x_;
    int base_y_;
    int width_;
    int height_;
    int color_;
    bool selected_;
    bool captured_;
    std::string texturePath_;
    sf::Texture texture_;
    sf::Sprite sprite_;
    
public:
    Piece(int x, int y, int width, int height, int color);
    ~Piece();

    virtual sf::Sprite &getSprite();
    virtual std::pair<int, int> getCoordinates();
    virtual std::pair<int, int> getBaseCoordinates();
    virtual int getColor();
    virtual void setCoordinates(int x, int y);
    virtual void setBaseCoordinates(int x, int y);
    virtual void setSelected(bool selected);
    virtual bool isSelected();
    virtual bool isCaptured();
    virtual void setCaptured(bool captured);
};

#endif // __PIECE_H__