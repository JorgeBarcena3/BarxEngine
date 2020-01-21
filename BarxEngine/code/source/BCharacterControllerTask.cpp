// File: BCharacterControllerTask.cpp
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
#include "..\headers\BCharacterControllerTask.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BCharacterController.hpp"
#include "..\headers\BKeyboardComponent.hpp"
#include "..\headers\BScene.hpp"
#include "..\headers\BKeyboard.hpp"

BCharacterControllerTask::BCharacterControllerTask(shared_ptr<BEntity> _entity, shared_ptr<BCharacterControllerComponent> _component) : BTask(TASKPRIORITY::ENTITYUPDATES)
{
    transform    = _entity->getTransform();
    component    = _component;
    InputManager = _entity->getScene()->getRootEntity()->getComponent<BKeyboardComponent>();
}

bool BCharacterControllerTask::initialize()
{
    return true;
}

bool BCharacterControllerTask::finalize()
{
    return true;
}

bool BCharacterControllerTask::execute(float time)
{
    if (InputManager->Keyboard->isKeyPresed(component->Up))
    {
        transform->position.z -= 0.001f * component->speed;
    }
    else  if (InputManager->Keyboard->isKeyPresed(component->Down))
    {
        transform->position.z += 0.001f * component->speed;

    }

    if (InputManager->Keyboard->isKeyPresed(component->Left))
    {
        transform->position.x -= 0.001f * component->speed;

    }
    else  if (InputManager->Keyboard->isKeyPresed(component->Right))
    {
        transform->position.x += 0.001f * component->speed;

    }

    return true;
}
