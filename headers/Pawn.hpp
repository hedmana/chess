#ifndef __PAWN_H__
#define __PAWN_H__

#include "Piece.hpp"

class Pawn : public Piece
{
public:
    Pawn(int x, int y, int width, int height, int color);
    ~Pawn();
};

#endif // __PAWN_H__