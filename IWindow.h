#ifndef IWINDOW_H_INCLUDED
#define IWINDOW_H_INCLUDED

#include <SDL2/SDL.h>

class IWindow{
public:
    virtual SDL_Window* getSDLWindow() = 0;
    virtual bool isOpen() = 0;
    virtual void close() = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
};

#endif // IWINDOW_H_INCLUDED
