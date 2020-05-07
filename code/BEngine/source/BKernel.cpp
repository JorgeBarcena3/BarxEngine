// File: BKernel.cpp
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

#include "..\headers\BKernel.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BAlgoritmosDeOrdenacion.hpp"
#include "..\headers\BScene.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BWindowTask.hpp"
#include <SDL.h>
#include <SDL_timer.h>


BKernel::BKernel(BScene * _scene)
{
    BTasks = std::vector< shared_ptr<BTask> >();
    scene = _scene;
    paused = false;
}

BKernel::~BKernel()
{
}

void BKernel::addTask(shared_ptr<BTask> task)
{

    if (task != nullptr)
    {
        BTasks.push_back(task);
        task->setKernel(this);
    }

}

void BKernel::run()
{

    exit = false;

    BAlgoritmosDeOrdenacion::algoritmoBurbuja<shared_ptr<BTask>>(BTasks.data(), BTasks.size());

    for (auto task : BTasks)
    {
        task->initialize();
    }

    auto name = BWindowTask::instance->windowName;

    auto window = BWindowTask::instance->getSDL_Window();

    BTimer timer;
    timer.start();

    float sec = 0;
    int frames = 0;
    SDL_SetWindowTitle(window, (name + " FPS [ 60 ]").c_str());

    short timePerFrame = 1000 / 60; // miliseconds
    float deltatime = timer.timeDeltatime();

    do
    {

        deltatime = timer.timeDeltatime();

        if (sec > 0.5)
        {
            SDL_SetWindowTitle(window, (name + " FPS [ " + to_string(frames * 2) + " ]").c_str());
            sec = 0;
            frames = 0;

        }

        sec += deltatime;
        frames++;


        //Limitamos a 60 el numero de FPS
        if (deltatime < timePerFrame)
        {
            SDL_Delay(timePerFrame - deltatime);
        }

        if (!paused)
        {
            for (auto task : BTasks)
            {
                if (!task->execute(deltatime))
                    exit = true;
            }

            removeEntitiesQueue();
        }

    } while (!exit);

    for (auto task : BTasks)
    {
        task->finalize();
    }

}

void BKernel::stop()
{
    exit = true;
}

void BKernel::pause() {
    paused = true;
}

void BKernel::resume()
{
    paused = false;
}

BScene * BKernel::getScene()
{
    return ( scene );
}

void BKernel::removeTaskForEntity(BEntity* entity)
{
    for (int i = 0; i < BTasks.size(); i++)
    {
        if (BTasks[i]->getId() == entity->getId())
        {
            toRemoveTask.push_back(BTasks[i]);
        }
    }
}

void BKernel::removeEntitiesQueue()
{

    for (auto bTask : toRemoveTask)
    {
        bTask->finalize();
        auto it = std::find(BTasks.begin(), BTasks.end(), bTask); 
        BTasks.erase(it);
    }

    toRemoveTask.clear();
    
}
