// File: BInputHandlerTask.cpp
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