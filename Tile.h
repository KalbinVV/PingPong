#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include "ISprite.h"
#include "Vec2.h"

class Tile : public ISprite{
private:
    Vec2 position;
    Vec2 size;
public:
    Tile(Vec2 size);
    void draw(SDL_Renderer* renderer) override;
    Vec2 getSize();
    Vec2 getPosition();
    void setPosition(Vec2 position);
};

#endif // TILE_H_INCLUDED
