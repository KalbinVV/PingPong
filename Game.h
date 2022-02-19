#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Window.h"
#include "Renderer.h"
#include "Tile.h"
#include "Ball.h"

class Game{
private:
    Window window;
    Renderer renderer;
    Tile player;
    Tile enemy;
    Ball ball;
    int tileSpeed;
    int ballSpeed;
    bool isNotLose;
    bool autoGame;
    void handleEvents();
    void update();
    void render();
    void checkIntersect();
    void updateEnemyPosition();
public:
    Game(const char* title, int width, int height, Uint32 rendererFlags, Vec2 tileSize, Vec2 ballSize);
};

#endif // GAME_H_INCLUDED
