#include <SDL.h>
#include "..//headers/BTask.hpp"
#include "../headers/BWindowTask.hpp"
#include "..//headers/BtypeDef.hpp"
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

};

BWindowTask::~BWindowTask()
{
    if (gl_context) SDL_GL_DeleteContext(gl_context);
    if (window) SDL_DestroyWindow(window);
};

void BWindowTask::set_fullscreen(uint32_t type)
{
    SDL_SetWindowFullscreen(window, type);
};

void BWindowTask::set_windowed()
{
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    set_size(width, heigth);
};

unsigned BWindowTask::get_width() const
{
    int width = 0, height;

    if (window) SDL_GetWindowSize(window, &width, &height);

    return unsigned(width);
}

unsigned BWindowTask::get_height() const
{
    int width, height = 0;

    if (window) SDL_GetWindowSize(window, &width, &height);

    return unsigned(height);
}


void BWindowTask::set_windowTitle(const char* title)
{
    SDL_SetWindowTitle(window, title);
};

void BWindowTask::set_position(int new_left_x, int new_top_y)
{
    SDL_SetWindowPosition(window, new_left_x, new_top_y);
};

void BWindowTask::set_size(int new_width, int new_height)
{
    SDL_SetWindowSize(window, new_width, new_height);
};

void BWindowTask::swap_buffers() const
{
    if (gl_context) SDL_GL_SwapWindow(window);
};

void BWindowTask::clear() const
{
    //glClearColor(0.52f,0.8f,0.9f,1); //AZUL CIELO
    glClearColor(0.2f, 0.2f, 0.2f, 1.f);
    if (gl_context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
};

bool BWindowTask::initialize()
{
    return true;
};

bool BWindowTask::finalize()
{
    return true;
};

bool BWindowTask::execute(float time)
{
      return true;
};
