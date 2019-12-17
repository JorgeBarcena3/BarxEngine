// This is free code released into the public domain.
// Drafted by Ángel on March 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

#pragma once

#include <SDL.h>
#include <string>
#include <cassert>

/*
* Clase que maneja la ventana
*/
class BWindow
{

public:

    enum Fullscreen_Type
    {
        REAL = SDL_WINDOW_FULLSCREEN,
        DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP
    };

private:

    SDL_Window* window;
    SDL_GLContext gl_context;
    
    int width;
    int heigth;

public:

    BWindow(const std::string& title, int _width, int _height, bool fullscreen = false)
    {

        width = _width;
        heigth = _height;

        window = SDL_CreateWindow
        (
            title.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            _width,
            _height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
        );

        assert(window != nullptr);

        gl_context = SDL_GL_CreateContext(window);

        if (fullscreen)
        {
            set_fullscreen();
        }

    }

    ~BWindow()
    {
        SDL_GL_DeleteContext(gl_context);
        SDL_DestroyWindow(window);
    }

    void set_fullscreen(Uint32 type = SDL_WINDOW_FULLSCREEN)
    {
        SDL_SetWindowFullscreen(window, type);
    }

    void set_windowed()
    {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        set_size(width, heigth);
    }

    void set_windowTitle(const char* title)
    {
        SDL_SetWindowTitle(window, title);
    }

    void set_position(int new_left_x, int new_top_y)
    {
        SDL_SetWindowPosition(window, new_left_x, new_top_y);
    }

    void set_size(int new_width, int new_height)
    {
        SDL_SetWindowSize(window, new_width, new_height);
    }

};

