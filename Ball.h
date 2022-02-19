#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "Tile.h"
#include "Vec2.h"

class Ball : public Tile{
private:
    Vec2 velocity;
public:
    Ball(Vec2 size);
    Vec2 getVelocity();
    void setVelocity(Vec2);
};

#endif // BALL_H_INCLUDED
