// File: BControlTask.cpp
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

#include "..\headers\BScene.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BControlTask.hpp"
#include "..\headers\BWindowTask.hpp"
#include "..\headers\BRenderTask.hpp"
#include "..\headers\BRenderObjectTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include <Render_Node.hpp>
#include <SDL.h>


BControlTask::BControlTask(shared_ptr<BEntity> _entityReference) : BTask(TASKPRIORITY::ENTITYUPDATES)
{
    entityReference = _entityReference;
    //myFunction = funcion;

}

bool BControlTask::initialize()
{
    return true;
}

bool BControlTask::finalize()
{
    return true;
}

bool BControlTask::execute(float time)
{
    if (myFunction)
        myFunction(time, entityReference);

    return true;
}
