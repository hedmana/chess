#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "Piece.hpp"

class Queen : public Piece
{
public:
    Queen(int x, int y, int width, int height, int color);
    ~Queen();
};

#endif // __QUEEN_H__