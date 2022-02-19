#include "Window.h"
#include <iostream>

Window::Window(const char* title, int width, int height) : size(width, height){
    sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 size.x, size.y, SDL_WINDOW_SHOWN);
    windowIsOpen = true;
    if(sdlWindow == NULL){
        windowIsOpen = false;
        std::cerr << SDL_GetError() << std::endl;
    }
}

SDL_Window* Window::getSDLWindow(){
    return sdlWindow;
}

bool Window::isOpen(){
    return windowIsOpen;
}

void Window::close(){
    windowIsOpen = false;
}

int Window::getWidth(){
    return size.x;
}

int Window::getHeight(){
    return size.y;
}

Window::~Window(){
    SDL_DestroyWindow(sdlWindow);
}

