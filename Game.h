#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Window.h"
#include "Renderer.h"
#include "Tile.h"

class Game{
private:
    Window window;
    Renderer renderer;
    Tile player;
    Tile enemy;
    Tile ball;
    int tileSpeed;
    int ballSpeed;
    Vec2 ballVelocity;
    void handleEvents();
    void update();
    void render();
    void checkIntersect();
    bool isNotLose;
public:
    Game(const char* title, int width, int height, Uint32 rendererFlags, Vec2 tileSize, Vec2 ballSize);
};

#endif // GAME_H_INCLUDED
