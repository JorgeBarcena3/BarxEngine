#include "..\headers\BPhysicsTask.hpp"
#include "../headers/BScene.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BWindow.hpp"

BPhysics_task::BPhysics_task()
{
}

bool BPhysics_task::initialize()
{
    return true;
}

bool BPhysics_task::finalize()
{
    return true;
}

bool BPhysics_task::run(float time)
{
    return true;
}


BWindow_Task::BWindow_Task()
{
}

bool BWindow_Task::initialize()
{
    instance = BWindow::instance;

    if (instance == nullptr)
    {
        BWindow* window = new BWindow("Test", 600, 600);
        instance = shared_ptr< BWindow >(window);

    }

    return true;
}

bool BWindow_Task::finalize()
{
    instance->~BWindow();
    return true;
}

bool BWindow_Task::run(float time)
{

    SDL_Event event;

    while (SDL_PollEvent(&event) > 0)
    {
        if (event.type == SDL_QUIT)
        {
            return false;
        }
    }

    return true;
}
