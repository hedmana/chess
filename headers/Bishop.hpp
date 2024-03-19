#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "Piece.hpp"

class Bishop : public Piece
{
public:
    Bishop(int x, int y, int width, int height, int color);
    ~Bishop();
};

#endif // __BISHOP_H__