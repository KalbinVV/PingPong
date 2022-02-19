#include "Vec2.h"

Vec2::Vec2(int x, int y){
    this->x = x;
    this->y = y;
}

Vec2::Vec2(const Vec2& anotherVec){
    this->x = anotherVec.x;
    this->y = anotherVec.y;
}

Vec2 Vec2::add(int x, int y){
    Vec2 resultVec(*this);
    resultVec.x += x;
    resultVec.y += y;
    return resultVec;
}
