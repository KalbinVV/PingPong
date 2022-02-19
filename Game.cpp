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
    tileSpeed = 15;
    ballSpeed = 8;
    ball.setVelocity(Vec2({
        x: -ballSpeed,
        y: ballSpeed / 2
    }));
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
                    case SDL_SCANCODE_DOWN:
                    case SDL_SCANCODE_S:{
                        Vec2 newPosition = player.getPosition().add(0, tileSpeed);
                        if(newPosition.y <= window.getHeight() - player.getSize().y){
                            player.setPosition(newPosition);
                        }
                        break;
                    }
                    case SDL_SCANCODE_UP:
                    case SDL_SCANCODE_W:{
                        Vec2 newPosition = player.getPosition().add(0, -tileSpeed);
                        if(newPosition.y >= 0){
                            player.setPosition(newPosition);
                        }
                        break;
                    }
                    case SDL_SCANCODE_R:
                        if(!isNotLose){
                            isNotLose = true;
                            ball.setPosition(Vec2{
                                x: window.getWidth() / 2,
                                y: window.getHeight() / 2
                            });
                        }
                        break;
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
        Vec2 resultVelocity(ball.getVelocity());
        resultVelocity.x = -resultVelocity.x;
        resultVelocity.y = (choose ? -resultVelocity.y : resultVelocity.y);
        ball.setVelocity(resultVelocity);
    }else if(ballRect.y <= 0 || ballRect.y >= window.getHeight() - ballRect.h){
        Vec2 resultVelocity(ball.getVelocity());
        resultVelocity.y = -resultVelocity.y;
        ball.setVelocity(resultVelocity);
    }else if(ballRect.x <= 0 || ballRect.x >= window.getWidth() - ballRect.h){
        isNotLose = false;
    }
}

void Game::updateEnemyPosition(){
    if(ball.getPosition().y > enemy.getPosition().y && enemy.getPosition().y <= window.getHeight() - enemy.getSize().y){
        enemy.setPosition(enemy.getPosition().add(0, ballSpeed));
    }else if(ball.getPosition().y < enemy.getPosition().y && enemy.getPosition().y >= 0){
        enemy.setPosition(enemy.getPosition().add(0, -ballSpeed));
    }
}

void Game::update(){
    Vec2 ballVelocity = ball.getVelocity();
    ball.setPosition(ball.getPosition().add(ballVelocity.x, ballVelocity.y));
    checkIntersect();
    updateEnemyPosition();
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
