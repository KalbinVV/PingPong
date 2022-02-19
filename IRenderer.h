#ifndef IRENDERER_H_INCLUDED
#define IRENDERER_H_INCLUDED

#include "SDL2/SDL.h"

#include "IWindow.h"
#include "ISprite.h"

class IRenderer{
public:
    virtual SDL_Renderer* getSDLRenderer() = 0;
    virtual void bindWindow(IWindow* window) = 0;
    virtual void update() = 0;
    virtual void draw(ISprite* sprite) = 0;
};

#endif // IRENDERER_H_INCLUDED
