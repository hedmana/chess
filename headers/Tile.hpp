#ifndef __TILE_H__
#define __TILE_H__

#include <SFML/Graphics.hpp>

#include "Enums.hpp"

class Tile
{
private:
    int x_;
    int y_;
    int width_;
    int height_;
    int color_;
    sf::RectangleShape sprite_;
    bool occupied_;

public:
    Tile(int x, int y, int width, int height, int color);
    ~Tile();

    int getColor() const;
    sf::RectangleShape getSprite() const;
    std::pair<int, int> getPosition();
    bool isOccupied() const;
    void setOccupied(bool occupied);
};

#endif // __TILE_H__