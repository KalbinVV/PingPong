#ifndef ISPRITE_H_INCLUDED
#define ISPRITE_H_INCLUDED

#include <SDL2/SDL.h>

class ISprite{
public:
    virtual void draw(SDL_Renderer* renderer) = 0;
};

#endif // ISPRITE_H_INCLUDED
