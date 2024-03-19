#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "Piece.hpp"

class Knight : public Piece
{
public:
    Knight(int x, int y, int width, int height, int color);
    ~Knight();
};

#endif // __KNIGHT_H__