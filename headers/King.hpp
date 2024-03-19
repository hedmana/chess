#ifndef __KING_H__
#define __KING_H__

#include "Piece.hpp"

class King : public Piece
{
public:
    King(int x, int y, int width, int height, int color);
    ~King();
};

#endif // __KING_H__