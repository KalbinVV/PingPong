#ifndef VEC2_H_INCLUDED
#define VEC2_H_INCLUDED

class Vec2{
public:
    int x;
    int y;
    Vec2(int x = 0, int y = 0);
    Vec2(const Vec2& anotherVec);
    Vec2 add(int x, int y);
};

#endif // VEC2_H_INCLUDED
