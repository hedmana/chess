#ifndef __ROOK_H__
#define __ROOK_H__

#include "Piece.hpp"

class Rook : public Piece
{
public:
    Rook(int x, int y, int width, int height, int color);
    ~Rook();
};

#endif // __ROOK_H__