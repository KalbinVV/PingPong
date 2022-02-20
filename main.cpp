#include <SDL2/SDL.h>
#include "Game.h"

int main(int argc, char *argv[]){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    Vec2 tileSize = Vec2{
        x: 15,
        y: 100
    };
    Vec2 ballSize = Vec2{
        x: 20,
        y: 20
    };
    Game game("PingPong", 800, 600, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC, tileSize, ballSize);
    SDL_Quit();
    return 0;
}
