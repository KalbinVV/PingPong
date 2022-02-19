#include "Game.h"
#include <random>
#include <ctime>

Game::Game(const char* title, int width, int height, Uint32 rendererFlags, Vec2 tileSize, Vec2 ballSize)
: window(title, width, height), renderer(rendererFlags), player(tileSize), enemy(tileSize), ball(ballSize){
    player.setPosition(Vec2{
        x: 0,
        y: window.getHeight() / 2
    });
    enemy.setPosition(Vec2{
        x: window.getWidth() - enemy.getSize().x,
        y: window.getHeight() / 2
    });
    ball.setPosition(Vec2{
        x: window.getWidth() / 2,
        y: window.getHeight() / 2
    });
    renderer.bindWindow(&window);
    tileSpeed = 10;
    ballSpeed = 4;
    ballVelocity = Vec2({
        x: -ballSpeed,
        y: ballSpeed / 2
    });
    isNotLose = true;
    while(window.isOpen()){
        handleEvents();
        if(isNotLose){
            update();
        }
        render();
    }
}

void Game::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            window.close();
        }else{
            if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.scancode){
                    case SDL_SCANCODE_S:{
                        Vec2 newPosition = player.getPosition().add(0, tileSpeed);
                        if(newPosition.y <= window.getHeight() - player.getSize().y){
                            player.setPosition(newPosition);
                        }
                        break;
                    }
                    case SDL_SCANCODE_W:{
                        Vec2 newPosition = player.getPosition().add(0, -tileSpeed);
                        if(newPosition.y >= 0){
                            player.setPosition(newPosition);
                        }
                        break;
                    }
                    case SDL_SCANCODE_DOWN:{
                        Vec2 newPosition = enemy.getPosition().add(0, tileSpeed);
                        if(newPosition.y <= window.getHeight() - enemy.getSize().y){
                            enemy.setPosition(newPosition);
                        }
                        break;
                    }
                    case SDL_SCANCODE_UP:{
                        Vec2 newPosition = enemy.getPosition().add(0, -tileSpeed);
                        if(newPosition.y >= 0){
                            enemy.setPosition(newPosition);
                        }
                    }
                    default:
                        break;
                }
            }
        }
    }
}

void Game::checkIntersect(){
    SDL_Rect ballRect{
        x: ball.getPosition().x,
        y: ball.getPosition().y,
        w: ball.getSize().x,
        h: ball.getSize().y
    };
    SDL_Rect playerRect{
        x: player.getPosition().x,
        y: player.getPosition().y,
        w: player.getSize().x,
        h: player.getSize().y
    };
    SDL_Rect enemyRect{
        x: enemy.getPosition().x,
        y: enemy.getPosition().y,
        w: enemy.getSize().x,
        h: enemy.getSize().y
    };
    if(SDL_HasIntersection(&ballRect, &playerRect) || SDL_HasIntersection(&ballRect, &enemyRect)){
        srand(time(0));
        int choose = rand() % 2;
        ballVelocity.x = -ballVelocity.x;
        ballVelocity.y = (choose ? -ballVelocity.y : ballVelocity.y);
    }else if(ballRect.y <= 0 || ballRect.y >= window.getHeight() - ballRect.h){
        ballVelocity.y = -ballVelocity.y;
    }else if(ballRect.x <= 0 || ballRect.x >= window.getWidth() - ballRect.h){
        isNotLose = false;
    }
}

void Game::update(){
    ball.setPosition(ball.getPosition().add(ballVelocity.x, ballVelocity.y));
    checkIntersect();
}

void Game::render(){
    if(isNotLose){
        renderer.clearScreen(SDL_Color{
            r: 0,
            g: 0,
            b: 0,
            a: 255
        });
    }else{
        renderer.clearScreen(SDL_Color{
            r: 255,
            g: 0,
            b: 0,
            a: 255
        });
    }
    renderer.draw(&player);
    renderer.draw(&enemy);
    renderer.draw(&ball);
    renderer.update();
}
