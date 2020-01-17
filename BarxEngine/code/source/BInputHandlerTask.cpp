#include "..\headers\BInputHandlerTask.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BKernel.hpp"
#include "..\headers\BMessage.hpp"
#include "..\headers\BScene.hpp"
#include <SDL.h>


BMyInputHandlerTask::BMyInputHandlerTask(bool active) : BTask(TASKPRIORITY::INPUTSYSTEM)
{
}

bool BMyInputHandlerTask::initialize()
{
    return true;
}

bool BMyInputHandlerTask::finalize()
{
    return true;
}

bool BMyInputHandlerTask::execute(float time)
{
    SDL_Event event;

    while (SDL_PollEvent(&event) > 0)
    {
        if (event.type == SDL_QUIT)
        {
            kernel->stop();
        }
        else if (event.type == SDL_KEYDOWN)
        {
            BMessage message("Keyboard");
            message.add_parameter("KeyDown", SDL_GetKeyName(event.key.keysym.sym));
            kernel->getScene()->getDispacher()->Send(message);
            
        }
        else if (event.type == SDL_KEYUP)
        {
            BMessage message("Keyboard");
            message.add_parameter("KeyUp", SDL_GetKeyName(event.key.keysym.sym));
            kernel->getScene()->getDispacher()->Send(message);

        }
    }

    return true;
}


