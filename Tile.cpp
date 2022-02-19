#include "Tile.h"

Tile::Tile(Vec2 size){
    this->size = size;
}

void Tile::draw(SDL_Renderer* renderer){
    SDL_Rect rect{
        x: position.x,
        y: position.y,
        w: size.x,
        h: size.y
    };
    SDL_RenderFillRect(renderer, &rect);
}

Vec2 Tile::getSize(){
    return size;
}

Vec2 Tile::getPosition(){
    return position;
}

void Tile::setPosition(Vec2 position){
    this->position = position;
}
