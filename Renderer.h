#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include "IRenderer.h"

class Renderer : public IRenderer{
private:
    SDL_Renderer* sdlRenderer;
    Uint32 rendererFlags;
public:
    Renderer(Uint32 rendererFlags);
    void bindWindow(IWindow* window) override;
    SDL_Renderer* getSDLRenderer() override;
    void update() override;
    void draw(ISprite* sprite) override;
    void clearScreen(SDL_Color color);
    ~Renderer();
};

#endif // RENDERER_H_INCLUDED
