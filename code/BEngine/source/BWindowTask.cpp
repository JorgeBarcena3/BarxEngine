// File: BWindowTask.cpp
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2019  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "..\headers\BTask.hpp"
#include "..\headers\BWindowTask.hpp"
#include "..\headers\BtypeDef.hpp"
#include <SDL.h>
#include <OpenGL.hpp>

shared_ptr< BWindowTask > BWindowTask::instance = nullptr;

enum Fullscreen_Type
{
    REAL = SDL_WINDOW_FULLSCREEN,
    DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP
};

BWindowTask::BWindowTask(const std::string& title, int _width, int _height, bool fullscreen) : BTask(TASKPRIORITY::WINDOW)
{
    if (instance == nullptr)
    {

        BWindowTask::instance = shared_ptr< BWindowTask >(this);
        width = _width;
        heigth = _height;
        windowName = title;

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

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

        gl_context = new SDL_GLContext(SDL_GL_CreateContext(window));

        if (gl_context && glt::initialize_opengl_extensions())
        {
            if (fullscreen)
            {
                SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
            }
        }
    }
    else
    {
        width = instance->width;
        heigth = instance->heigth;
        window = instance->window;
        gl_context = instance->gl_context;

    }

}

BWindowTask::~BWindowTask()
{
    if (gl_context) SDL_GL_DeleteContext(gl_context);
    if (window) SDL_DestroyWindow(window);
}

void BWindowTask::setFullScreen(uint32_t type)
{
    SDL_SetWindowFullscreen(window, type);
}

void BWindowTask::setWindowed()
{
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    setSize(width, heigth);
}

unsigned BWindowTask::getWidth() const
{
    int width = 0, height;

    if (window) SDL_GetWindowSize(window, &width, &height);

    return unsigned(width);
}

unsigned BWindowTask::getHeight() const
{
    int width, height = 0;

    if (window) SDL_GetWindowSize(window, &width, &height);

    return unsigned(height);
}

void BWindowTask::setWindowTitle(const char* title)
{
    SDL_SetWindowTitle(window, title);
}

void BWindowTask::setPosition(int new_left_x, int new_top_y)
{
    SDL_SetWindowPosition(window, new_left_x, new_top_y);
}

void BWindowTask::setSize(int new_width, int new_height)
{
    SDL_SetWindowSize(window, new_width, new_height);
}

void BWindowTask::swapBuffers() const
{
    if (gl_context) SDL_GL_SwapWindow(window);
}

void BWindowTask::clear() const
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.f);
    if (gl_context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

SDL_Window* BWindowTask::getSDL_Window()
{
    return window;
}

bool BWindowTask::initialize()
{
    return true;
}

bool BWindowTask::finalize()
{
    return true;
}

bool BWindowTask::execute(float time)
{
      return true;
}