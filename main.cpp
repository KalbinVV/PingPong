#include <SDL2/SDL.h>
#include "Game.h"

int main(int argc, char *argv[]){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    Game game("PingPong", 800, 600, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC, Vec2{
        x: 15,
        y: 100
    }, Vec2{
        x: 20,
        y: 20
    });
    SDL_Quit();
    return 0;
}
