#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SDL2/SDL.h>

#include "IWindow.h"
#include "Vec2.h"

class Window : public IWindow{
private:
    SDL_Window* sdlWindow;
    bool windowIsOpen;
    Vec2 size;
public:
    Window(const char* title, int width, int height);
    SDL_Window* getSDLWindow() override;
    bool isOpen() override;
    void close() override;
    int getWidth() override;
    int getHeight() override;
    ~Window();
};

#endif // WINDOW_H_INCLUDED
