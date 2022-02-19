#include "Renderer.h"
#include <iostream>

Renderer::Renderer(Uint32 rendererFlags){
    this->rendererFlags = rendererFlags;
    sdlRenderer = nullptr;
}

void Renderer::bindWindow(IWindow* window){
    if(!sdlRenderer) SDL_DestroyRenderer(sdlRenderer);
    sdlRenderer = SDL_CreateRenderer(window->getSDLWindow(), -1, rendererFlags);
    if(sdlRenderer == NULL){
        std::cerr << SDL_GetError() << std::endl;
    }
}

SDL_Renderer* Renderer::getSDLRenderer(){
    return sdlRenderer;
}

void Renderer::update(){
    SDL_RenderPresent(sdlRenderer);
}

void Renderer::draw(ISprite* sprite){
    sprite->draw(getSDLRenderer());
}

void Renderer::clearScreen(SDL_Color color){
    SDL_SetRenderDrawColor(sdlRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(sdlRenderer);
    SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
}

Renderer::~Renderer(){
    SDL_DestroyRenderer(sdlRenderer);
}
