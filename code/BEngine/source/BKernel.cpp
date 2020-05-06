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


BKernel::BKernel(shared_ptr<BScene> _scene)
{
    BTasks = std::vector< shared_ptr<BTask> >();
    scene = _scene;
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

    float time = 1.f / 30.f;

    BTimer timer;

    int now = timer.elapsedMiliseconds();
    int lastFrame = timer.elapsedMiliseconds();
    long TimeToSleep = (1000 / 60) / 1000;

    do
    {
        now = timer.elapsedMiliseconds();
        int delta = now - lastFrame;
        lastFrame = now;

        //Limitamos a 60 el numero de FPS
        if (delta < TimeToSleep)
        {
            std::this_thread::sleep_for(std::chrono::seconds(TimeToSleep));
        }

        for (auto task : BTasks)
        {
            if (!task->execute(time))
                exit = true;
        }

        time = (float)timer.elapsedMiliseconds();


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

shared_ptr<BScene> BKernel::getScene()
{
    return scene;
}