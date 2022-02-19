#include "Ball.h"

Ball::Ball(Vec2 size) : Tile(size){}

Vec2 Ball::getVelocity(){
    return velocity;
}

void Ball::setVelocity(Vec2 velocity){
    this->velocity = velocity;
}
