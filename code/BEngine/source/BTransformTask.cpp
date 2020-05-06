// File: BTranformTask.cpp
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
#include "..\headers\BTranformTask.hpp"
#include "..\headers\BWindowTask.hpp"
#include "..\headers\BRenderTask.hpp"
#include "..\headers\BRenderObjectTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BPhysicsComponent.hpp"
#include <Render_Node.hpp>
#include <SDL.h>

#define ANGLE_TO_RADIANS ( 3.1514 / 180 )

BTransformTask::BTransformTask(string _id, shared_ptr<BTransformComponent> _transformComponent) : BTask(TASKPRIORITY::TRANSFORM)
{
    id = _id;
    transform = _transformComponent;
}

bool BTransformTask::initialize()
{

   
    return true;
}

bool BTransformTask::finalize()
{
    return true;
}

bool BTransformTask::execute(float time)
{
   
    glm::mat4 trans = glm::mat4(1.0f);

    trans = glm::translate(trans, glm::vec3(transform->position.x, transform->position.y, transform->position.z));
    trans = glm::rotate(trans, glm::radians(transform->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    trans = glm::rotate(trans, glm::radians(transform->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    trans = glm::rotate(trans, glm::radians(transform->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

    transform->transformationMatrix = trans;
    
    return true;
}